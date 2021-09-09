/*
Max sum in the configuration 

Given an array(0-based indexing), you have to find the max sum of i*A[i] where A[i] is the element at index i in the array. The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.

Example 1:

Input:
N = 4
A[] = {8,3,1,2}
Output: 29
Explanation: Above the configuration
possible by rotating elements are
3 1 2 8 here sum is 3*0+1*1+2*2+8*3 = 29
1 2 8 3 here sum is 1*0+2*1+8*2+3*3 = 27
2 8 3 1 here sum is 2*0+8*1+3*2+1*3 = 17
8 3 1 2 here sum is 8*0+3*1+1*2+2*3 = 11
Here the max sum is 29 
Your Task:
Your task is to complete the function max_sum which takes two arguments which is the array A [ ] and its size and returns an integer value denoting the required max sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1<=N<=104
1<=A[]<1000
*/
int max_sum(int arr[],int n)
{
    
    // To find the original sum.
    int maxSum = INT_MIN;
    int currSum = 0;
    int orgSum = 0;
    for(int i = 0; i < n; i++){
        currSum += i * arr[i];
        orgSum += arr[i];
    }
    //maxSum = currSum;
    
    // The concept is that, if we are considering that the first element will be moved at the last then:
    //	1. orginal sum - first index number or arr[i] , this sum will be subtracted from the currSum as all the positions apart from arr[i] are moving once to the left.
    // 	2. the second part is because as arr[i] is moving to the back/right, we need to now consider its constibution in the currSum.
    for(int i = 0; i < n; i++){
        currSum = currSum - (orgSum - arr[i]) + (arr[i] * (n - 1));
        maxSum = max(currSum , maxSum);
        
    }
    
    return maxSum;
}
