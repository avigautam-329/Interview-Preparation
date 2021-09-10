/*
Maximum Product Subarray 

Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.
Example 2:

Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is [2, 3, 4, 5] which gives product as 120.
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxProduct() which takes the array of integers arr and n as parameters and returns an integer denoting the answer.
Note: Use 64-bit integer data type to avoid overflow.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 = N = 500
-102 = Arri = 102
*/


// Function to find maximum product subarray
long long maxProduct(vector<int> arr, int n) {
	
	// I have done the explicit conversion due to the requirenments of the question.
	// Explanation in notebook. 
	
	
	// Holds the max and min till arr[i-1], the new values of both will depend on arr[i].
	long long  maxProduct = arr[0];
	long long  minProduct = arr[0];
	    
	long long maxSoFar = arr[0];
	for(int i = 1; i < n; i++){
	    if(arr[i] < 0){
            swap(maxProduct , minProduct);
	    }
	        
	    maxProduct = max((long long)arr[i] , maxProduct * (long long)arr[i]);
	    minProduct = min((long long)arr[i] , minProduct * (long long)arr[i]);
	        
	    maxSoFar = max(maxSoFar , maxProduct);
	}
	    
	return maxSoFar;
}
