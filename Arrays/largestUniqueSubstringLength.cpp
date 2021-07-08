#include <bits/stdc++.h>
using namespace std;

int length(char input[]){
	int count = 0;
	for(int i=0; input[i] != '\0'; ++i){
		count++;
	}
	return count;
}

// In this function we will only return the length of the largest unique substring.
int largestUniqueSubstring(char input[]){
	int n = length(input);
	
	int start = 0, end = 0;
	int maxLongestSubstring = 0;
	
	//Initialise an array/vector of length 256 with all values as -1.
	vector<int> lastIndex(256,-1);
	

	while(input[end] != '\0'){
		
		// We will see wether the last occurence is in the window or not.
		// If not then include the element in the window.
		if(lastIndex[input[end]] < start){
			end++;
		}else{
			
			// This is a tricky process for me.
			// We will see wether the current window is bigger or the window we can create after dropping
			// the unique element is bigger.
			
			// When we are calculating this, we haven't included the new element yet.
			// Here we are just checking if the current window has the largest length or not.
			int currentWindowLength = end - start;
			
			// If the current window is the largest we have encountered yet.
			if(currentWindowLength > maxLongestSubstring){
				maxLongestSubstring = currentWindowLength;
			}
			
			//Now we have to move our start to the next element of the last occurenece of the element/
			// we have to include in the window.
			start = lastIndex[input[end]] + 1;
			end++;
		}
		
		// Now we have to enter the index of occurence of our current element in lastIndex.
		lastIndex[input[end - 1]] = end - 1;	
	}
	
	// After the while loop ends, we still might havea substring which is bigger than the one currently being considered as max.
	// To check for this we will do the same thing again
	int currentWindowLength = end - start;
			
	// If the current window is the largest we have encountered yet.
	if(currentWindowLength > maxLongestSubstring){
		maxLongestSubstring = currentWindowLength;
	}
	
	return maxLongestSubstring;
}


int main(){
	char input[1000];
	cin.getline(input,1000);
	int max_len = largestUniqueSubstring(input);
	cout << max_len << endl;
	return 0;
}
