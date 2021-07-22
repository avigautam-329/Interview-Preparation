#include <iostream>
#include <vector>
using namespace std;

void helperFunction(int input[], int size1, int k, int startIndex, vector<int>& output, int size2){
	
	// Base case.
	if(startIndex == size1){
		if(k == 0){
			// Print output.
			for(auto x:output){
				cout << x << " ";
			}
			cout << endl;
            return;
		}else{
			return;
		}
	}

	vector<int> smallOutput;
	
	// First Case if we are not cosidering the current element.
	helperFunction(input, size1 , k , startIndex + 1, output, output.size());
	
    // This step reduces the time complexity by half approx. And that is kind of logical
    if(k > 0){
    	// Copying the elements from the output array to the small Output.
		for(int i = 0; i < size2; ++i){
			smallOutput.push_back(output.at(i));
		}
		smallOutput.push_back(input[startIndex]);
		helperFunction(input, size1 , k - input[startIndex], startIndex + 1, smallOutput, smallOutput.size());
    }   
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    vector<int> output;

    helperFunction(input,size,k,0,output,0);
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
  return 0;
}
