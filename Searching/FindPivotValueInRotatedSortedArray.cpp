class Solution {
public:
    // Basically we find the pivot value, soo pivot value is the largest value.
    // The element next to the largest value will be the smallest number as the array is sorted and rotated.
    int binarySearch(vector<int>& nums, int size){
        if(size == 1){
            return nums[0];
        }
        
        int start = 0, end = size - 1;
        
        while(start < end){
            int mid = start + (end- start)/2;
            
            if(nums[mid] > nums[mid + 1]){
                return nums[mid + 1];
            }
            else if(nums[start] <= nums[mid]){
                start = mid + 1;
            }else{
                end = mid;
            }
        }
        
        return nums[0];
    }
    
    int findMin(vector<int>& nums) {
        int pos = binarySearch(nums , nums.size());
        return pos;
    }
};
