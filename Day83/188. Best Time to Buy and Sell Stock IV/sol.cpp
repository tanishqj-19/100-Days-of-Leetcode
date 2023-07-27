class Solution {
    
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> after(2, vector<int>(k+1, 0));

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy < 2; buy++){
                for(int cap =1; cap<k+1; cap++){
                    if(buy == 1)
                        curr[buy][cap] = max(-prices[i] + after[0][cap],
                                       after[1][cap]);
                    else
                        curr[buy][cap] = max(prices[i] + after[1][cap-1],
                                   after[0][cap]);
                }
            }
            after = curr;
        }

        return after[1][k];

    }
    
};
