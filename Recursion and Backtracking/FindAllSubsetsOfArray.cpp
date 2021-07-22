#include <bits/stdc++.h>
using namespace std;

int helperFunction(int input[], int n, int capacity, int output[][20]){
	// I think this shoud be the base case.
	if(n == 0){
		if(capacity == 0){
			output[capacity][0] = 0;
			capacity++;
			return capacity;
		}else{
			return capacity;
		}
	}
	
	// Called Recursion
	capacity = helperFunction(input + 1, n - 1, capacity, output);
	
	// Now we will do the operation part.
	
	// The start variable is to copy the elements from before with the input[0] added.
	int start = 0;
	for(int i = capacity; i < capacity * 2; ++i){
		// I have done this to match the format of the answer given.
		output[i][0] = output[start][0] + 1;
        output[i][1] = input[0];
        int k = 1;
        
        // I have added 1 as the first element is already fixed and we are starting from the 2nd element.
		for(int j = 2; j <= output[start][0] + 1; ++j){
			output[i][j] = output[start][k++];
		}
		
        start++;
	}
	
	return 2 * capacity;
}

int subset(int input[], int n, int output[][20]) {
    // Write your code here
    int capacity = 0;
    
    return helperFunction(input, n, capacity,output);

}

int main() {
  int input[20],length, output[3500][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
