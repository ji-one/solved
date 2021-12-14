class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int cur = prices[0];
        
        for(int i = 1; i < prices.size(); i++){
            if(cur < prices[i]){
                profit += (prices[i] - cur);
            }
            cur = prices[i];
        }
        
       return profit; 
    }
};
