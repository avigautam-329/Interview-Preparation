/*
Trapping Rain Water 

Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
Explanation: 

Example 2:

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.
Example 3:

Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.

Your Task:
You don't need to read input or print anything. The task is to complete the function trappingWater() which takes arr[] and N as input parameters and returns the total amount of water that can be trapped.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

// This is a very different question from max rectangle in histogram or Containing most water.
	
long long trappingWater(int arr[], int n){
    // Initializing the variables.
    int *maxl = new int[n];
    int *maxr = new int[n];
        
    // Now we need to populate the max left array first.
    maxl[0] = arr[0];
    for(int i = 1; i < n; i++){
        maxl[i] = max(maxl[i - 1] , arr[i]);
    }
        
    // Now we need to populate the max right array.
    maxr[n - 1] = arr[n-1];
    for(int i = n - 2; i >= 0; i--){
        maxr[i] = max(maxr[i + 1] , arr[i]);
    }
        
    int *waterLevel = new int[n];
    for(int i = 0; i < n; i++){
        waterLevel[i] = min(maxr[i] , maxl[i]) - arr[i];
    }
        
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += waterLevel[i];
    }
        
    return sum;
}
