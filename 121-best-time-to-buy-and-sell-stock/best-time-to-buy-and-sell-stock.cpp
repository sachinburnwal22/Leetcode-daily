class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minStock = INT_MAX;
        for(int i=0; i<n; i++){
            if(prices[i] < minStock){
                minStock = prices[i];
            }else{
                int profit = prices[i] - minStock;
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};