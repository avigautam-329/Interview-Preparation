#include<bits/stdc++.h>
using namespace std;

void helperFunction(int *arr,int size, bool *curr_elem, int curr_no_elements, int curr_sum , bool *solution, int sum,int &min_diff, int startIndex){
	
	// If we have reached the end of the array.
	if(startIndex == size){
		return;
	}
	
	//  Now we have to check whether we have the required no. of elements to fit in the first array.
	if((size/2) - curr_no_elements > size - startIndex){
		return;
	}
	
	// Now as we have to include/exclude the current element.
	// First we will exclude the element and call forward.
	helperFunction(arr,size,curr_elem,curr_no_elements,curr_sum,solution,sum,min_diff,startIndex + 1);
	
	// Now we will include the element.
	curr_no_elements++;
	curr_elem[startIndex] = true;
	curr_sum += arr[startIndex];
	
	// Now we will move forward.
	if(curr_no_elements == (size/2)){
		// Now we have to check whether the diff is the new minimum or not.
		if(abs((sum/2) - curr_sum) < min_diff){
			min_diff = abs((sum/2) - curr_sum);
			
			// Now we have to copy this current distribution in the solution array.
			for(int i = 0; i < size; ++i){
				solution[i] = curr_elem[i];
			}
		}
	}else{
		helperFunction(arr,size,curr_elem,curr_no_elements,curr_sum,solution,sum,min_diff,startIndex+1);
	}
	
	curr_elem[startIndex] = false;
}

void tugOfWar(int *arr, int size){
	// We have to create a few arrays first.
	// 1. Array to keep track of inclusion and exclusion of current elements.
	// 2. Array of keeping track of inclusion and exclusion of the final solution array.
	
	bool *curr_elem = new bool[size];
	
	
	//This is to store the solution everytime current minimum differece is less than the final minimum difference.
	bool *solution = new bool[size];
	
	int sum = 0;
	int min_diff = INT_MAX;
	int curr_no_elements = 0;
	int startIndex = 0;
	
	
	for(int i = 0; i < size ; ++i){
		sum += arr[i];
		curr_elem[i] = solution[i] = false;
	}
	
	helperFunction(arr,size,curr_elem,curr_no_elements,0,solution,sum,min_diff,startIndex);
	
   	cout << "The first subset is: ";
    for (int i=0; i<size; i++)
    {
        if (solution[i] == true)
            cout << arr[i] << " ";
    }
    cout << "\nThe second subset is: ";
    for (int i=0; i<size; i++)
    {
        if (solution[i] == false)
            cout << arr[i] << " ";
    }

}

int main(){
	int n;
	cin >> n;
	
	int *input = new int[n];
	for(int i = 0; i < n; ++i){
		cin >> input[i];
	}
	
	// Now we will call the function.
	tugOfWar(input,n);
	return 0;
}
