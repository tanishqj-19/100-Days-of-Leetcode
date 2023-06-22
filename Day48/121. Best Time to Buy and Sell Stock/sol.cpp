class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, mini = prices[0], n = prices.size();
        int curr = 0;

        for(int i=1; i<n; i++){
            curr = prices[i] - mini;
            profit = max(profit, curr);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};
