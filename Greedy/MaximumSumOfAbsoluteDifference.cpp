/*
Given an array, we need to find the maximum sum of absolute difference of any permutation of the given array.
Examples: 
 

Input : { 1, 2, 4, 8 }
Output : 18
Explanation : For the given array there are 
several sequence possible
like : {2, 1, 4, 8}
       {4, 2, 1, 8} and some more.
Now, the absolute difference of an array sequence will be
like for this array sequence {1, 2, 4, 8}, the absolute
difference sum is 
= |1-2| + |2-4| + |4-8| + |8-1|
= 14
For the given array, we get the maximum value for
the sequence {1, 8, 2, 4}
= |1-8| + |8-2| + |2-4| + |4-1|
= 18

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMaxDiff(int* arr, int n){
	// To get the maximum possible difference between consecutive elements:
	//	1. We will have to keep a small element and a large elemenet next to each other.
	//	2. Only by doing this will we get a max consecutive difference.
	//	3. To do this but we will need to make an empty vector.
	//	4. And the push the elements in similar fashion into the vector.
	//	5. First small and then a big element.
	//	6. For elements having odd number of elements we will put the mid element at the end of this vector.
	sort(arr, arr + n);
	
	vector<int> diffArray;
	
	
	for(int i = 0; i < n/2; i++){
		diffArray.push_back(arr[i]);
		diffArray.push_back(arr[n - i - 1]);	
	}
	
	// If the array length is odd, then we need to push the mid at the end.
	if(n % 2 != 0){
		diffArray.push_back(arr[n / 2]);
	}
	
	int maxDiff = 0;
	for(int i = 0; i < n - 1; i++){
		maxDiff += abs(diffArray[i] - diffArray[i + 1]);
	}
	
	maxDiff += abs(diffArray[n - 1] - diffArray[0]);
	
	return maxDiff; 
}

int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int maxDiff = findMaxDiff(arr , n);
	
	cout << "The maximum possible difference is: " << maxDiff << endl; 
	
	return 0;
}
