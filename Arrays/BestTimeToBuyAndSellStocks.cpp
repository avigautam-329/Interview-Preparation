class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        
        int maxProfit = INT_MIN;
        while(r < prices.size()){
            if(prices[r] <= prices[l]){
                l = r;
                r++;
            }else{
                int currProfit = prices[r] - prices[l];
                maxProfit = max(maxProfit , currProfit);
                r++;
            }
        }
        
        if(maxProfit == INT_MIN){
            return 0;
        }
        
        return maxProfit;
    }
};
