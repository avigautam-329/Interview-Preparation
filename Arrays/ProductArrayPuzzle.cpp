/*
Product array puzzle 

Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].

Example 1:

Input:
n = 5
nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
Example 2:

Input:
n = 2
nums[] = {12,0}
Output:
0 12

Your Task:
You do not have to read input. Your task is to complete the function productExceptSelf() that takes array nums[] and n as input parameters and returns a list of n integers denoting the product array P. If the array has only one element the returned list should should contains one value i.e {1}
Note: Try to solve this problem without using the division operation.
 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
 

Constraints:
1 <= n <= 1000
0 <= numsi <= 200
Array may contain duplicates.
*/

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& arr, int n) {
       
        if(n == 1){
            arr[0] = 1;
            return arr;
        }
        // Since we cannot use a division operation, soo the next best approach I could think of is left and right traversal.
        
        // 1. Left traversal:
        //		- We maintain a mult array, while going to left, for mult[i] = The prodcut of left * the element on left.
        //		- We multiply the left element because mult[i-1] does not include arr[i-1];
        vector<long long int> mult(n , 1);
        
        for(int i = 1; i < n; i++){
            mult[i] = mult[i-1] * arr[i-1];
        }
        
        
        // 2. During right Traversal:
        //		- We will maintain the multiplication of the elements on the right of the current element.
		//		- multiply the current element with the multiplication of right elements only, since we already have left multiplication.
		//		- Update right multipication by multiplying it with arr[i]. 
        long long int right = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            mult[i] *= right;
            right *= arr[i];
        }
        
        return mult;
    }
};
