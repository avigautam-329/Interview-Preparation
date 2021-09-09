/*
Minimum distance between two numbers 

You are given an array A, of N elements. Find minimum index based distance between two elements of the array, x and y.

Example 1:

Input:
N = 4
A[] = {1,2,3,2}
x = 1, y = 2
Output: 1
Explanation: x = 1 and y = 2. There are
two distances between x and y, which are
1 and 3 out of which the least is 1.
Example 2:

Input:
N = 7
A[] = {86,39,90,67,84,66,62}
x = 42, y = 12
Output: -1
Explanation: x = 42 and y = 12. We return
-1 as x and y don't exist in the array.
Your Task:
Complete the function minDist() which takes the array, n, x and y as input parameters and returns the minimum distance between x and y in the array. If no such distance is possible then return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
0 <= A[i], x, y <= 105
*/

#include<iostream>
#include<cmath>
#include<climits>
using namespace std;


// Time Complexity = O(n).
// Space Complexity = O(1).
int minDistance(int *arr, int n, int x, int y){
	// We will follow the steps as:
	// 	1. Whenever we find a number, if the previous index has no element, then we will make this current value the previous.
	// 	2. When we find another occurence of x o r y , we will check if the number occured previously is not equal to this one.
	//	3. If not equal then it means that we have found a pair of x and y, soo we calculate the distance and make this current element the prev.
	
	int prev = -1,min_dist = INT_MAX;
	for(int i = 0; i < n; i++){
		if(arr[i] == x || arr[i] == y){
			if(prev != -1 && arr[prev] != arr[i]){
				// This means we have found a pair.
				min_dist = min(min_dist , i - prev);
				
			}
			
			prev = i;
		}
	}
	if(min_dist == INT_MAX){
		return -1;
	}
	return min_dist; 
}

int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int x,  y;
	cin >> x >> y;
	
	int distance = minDistance(arr , n, x, y);
	cout << distance;
	return 0;
}
