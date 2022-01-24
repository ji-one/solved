class Solution {
public:
    int maxProfit(vector<int>& prices) {
/* ver. 1
        int n = prices.size();
        int min[100001]; // min[i] : prices[0] ~ prices[i] 중 minimum
        int max[100001]; // max[i] : prices[i] ~ prices[n-1] 중 maximum
        int answer = 0;
        
        min[0] = prices[0];
        max[n-1] = prices[n-1];
        
        for(int i=1; i<prices.size(); i++){
            min[i] = (min[i-1] - prices[i]) > 0 ? prices[i] : min[i-1];
            max[n-i-1] = (max[n-i] - prices[n-i-1]) > 0 ? max[n-i] : prices[n-i-1];
        } 
     
        for(int i=0; i<n-1; i++){
            answer = (max[i+1] - min[i]) > answer ? max[i+1] - min[i] : answer;
        }
        
        return answer;
*/
        int answer = 0;
        int smallest = INT_MAX;
        
        for(auto price : prices){
            smallest = min(smallest, price);
            answer = max(answer, price-smallest);
        }
        return answer;
    }
    
};