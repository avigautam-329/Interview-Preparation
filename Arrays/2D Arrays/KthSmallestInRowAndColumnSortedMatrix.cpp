class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        if(matrix.size() == 0){
            return -1;
        }
        
        // We will use the nested binary search approach.
        int n = matrix.size();
        int lb = matrix[0][0];
        int ub = matrix[n - 1][n - 1];
        int x;
        while(lb <= ub){
            x = (lb + ub) / 2;
            int totalCount = 0;
            for(int i = 0; i < n; i++){
                int start = 0, end = n - 1;
                
                while(start <= end){
                    int mid = start + (end - start) / 2;
                    if(matrix[i][mid] <= x){
                        start = mid + 1;
                    }else{
                        end = mid - 1;
                    }
                }
                
                totalCount += start;
            }
            
            if(totalCount < k){
                lb = x + 1;
            }else{
                ub = x - 1;
            }
        }
        
        return x;
    }
};
