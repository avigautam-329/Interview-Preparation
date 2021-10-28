class Solution {
public:
    int binarySearch(vector<int>& nums ,int start, int end,int size, int target){
        if(start > end){
            return -1;
        }
        
        int mid = start + (end - start)/2;
        if(nums[mid] == target){
            return mid;
        }
        // We need to figure out that which part of the array is actually still sorted.
        if(nums[mid] >= nums[start]){
            // This means that the left part is sorted.
            if(target < nums[mid] && target >= nums[start]){
                return binarySearch(nums , start, mid - 1, size, target);
            }else{
                // That the element might exist in the unsorted part.
                return binarySearch(nums, mid + 1, end, size, target);
            }
        }else{
            // This means that my right part is sorted.
            if(target > nums[mid] && target <= nums[end]){
                return binarySearch(nums , mid + 1, end , size, target);
            }else{
                return binarySearch(nums , start , mid - 1, size , target);
            }
        }
    }
    
    
    int search(vector<int>& nums, int target) {
        int pos = binarySearch(nums,0 , nums.size() - 1,nums.size(),target);
        return pos;
    }
};
