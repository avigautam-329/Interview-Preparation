/*
209. Minimum Size Subarray Sum

Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.


Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
*/


// This is my implementation using a varibale sliding window.
// The Steps followed are:
//		1. First we need to initialize the 2 pointers.
//		2. start = 0 and end = 0
//		3. In the while loop we first need to add the element at the end.
//		4. If after the addition, the value goes over or equal to the target, we can try to find a sum by increasing the start pointer to find the min length subArray
//

class Solution {
public:
    int minSubArrayLen(int x, vector<int>& nums) {
        int minLength = INT_MAX;
        
        int start = 0, end = 0;
        int sum = 0;
        
        bool flag = false;
        while(end < nums.size()){
            sum += nums[end++];
            
            while(sum >= x && start <= end){
                flag = true;
                int temp = end - start;
                minLength = min(temp , minLength);
                sum -= nums[start++];
            }
        }
        
        if(!flag){
            return 0;
        }
        return minLength;
    }
};
