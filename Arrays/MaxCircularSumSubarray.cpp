/*
Max Circular Subarray Sum 

Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.


Example 1:

Input:
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output:
22
Explanation:
Starting from the last element
of the array, i.e, 12, and 
moving in a circular fashion, we 
have max subarray as 12, 8, -8, 9, 
-9, 10, which gives maximum sum 
as 22.
Example 2:

Input:
N = 8
arr[] = {10,-3,-4,7,6,5,-4,-1}
Output:
23
Explanation: Sum of the circular 
subarray with maximum sum is 23

Your Task:
The task is to complete the function circularSubarraySum() which returns a sum of the circular subarray with maximum sum.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).


Constraints:
1 <= N <= 106
-106 <= Arr[i] <= 106
*/

#include<bits/stdc++.h>
using namespace std;

int kadane(int *arr, int n){
	int currSum = arr[0];
	int maxSum = arr[0];
	
	for(int i = 1; i < n; i++){
		currSum = max(arr[i], currSum + arr[i]);
		
		if(currSum > maxSum){
			maxSum = currSum;
		}
	}
	
	return maxSum;
}

int maxCircularSum(int *arr, int n){
	

	
	// Step 1: Find the maxSumSubarray of the normal array.
	int maxSumSubarray = kadane(arr , n);
	if(maxSumSubarray < 0){
		return maxSumSubarray;
	}
	// Now for the second step, we already have the original sum, now we need to just find the minimum sum subarray.
	int orgSum = 0;
	for(int i = 0; i < n; i++){
		orgSum += arr[i];
		arr[i] *= -1;
	}
	
	int minimumSumSubarray = kadane(arr, n);
	int circularSumSubarray = orgSum + minimumSumSubarray;
	
	return max(maxSumSubarray , circularSumSubarray);
	
}

int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int maxSum = maxCircularSum(arr, n);
	cout << maxSum;
	
	return 0;
}
