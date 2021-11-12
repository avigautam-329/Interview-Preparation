class Solution {
public:
    int trap(vector<int>& arr) {
        // 2 pointer approach.
        int n = arr.size();
        int leftMax = 0; int rightMax = 0;
        int res = 0;
        int left = 0; int right = n - 1;
        
        while(left < right){
            // We have one condition to check initially.
            
            // This condition means that there is an element on the right that is greater than the current element.
            if(arr[left] <= arr[right]){
                if(arr[left] >= leftMax){
                    leftMax = arr[left];
                }else{
                    res += leftMax - arr[left];
                }
                left++;
            }else{
                if(arr[right] >= rightMax){
                    rightMax = arr[right];
                }else{
                    res += rightMax - arr[right];
                }
                right--;
            }
        }
        
        return res;
    }
};
