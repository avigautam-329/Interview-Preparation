class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n2 < n1){
            return findMedianSortedArrays(nums2 , nums1);
        }
        
        int start = 0, end = n1;
        while(start <= end){
            int cut1 = start + (end - start)/2;
            int cut2 = ((n1 + n2)/2) - cut1;
            
            int l1 = (cut1 == 0)?INT_MIN:nums1[cut1 - 1];
            int l2 = (cut2 == 0)?INT_MIN:nums2[cut2 - 1];
            int r1 = (cut1 == n1)?INT_MAX:nums1[cut1];
            int r2 = (cut2 == n2)?INT_MAX:nums2[cut2];
            
            if(l1 > r2){
                end = cut1 - 1;
            }else if(l2 > r1){
                start = cut1 + 1;
            }else{
                if((n1 + n2) % 2 == 0){
                    return (max(l1 , l2) + min(r1 ,r2))/2.0;
                }
                
                return min(r1,r2)/1.0;
            }
        }
        return 0.0;
    }
};
