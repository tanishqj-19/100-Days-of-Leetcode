class Solution {
    
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n =prices.size();
        vector<int> curr(2, 0), next(2, 0);
        next[0] = next[1] = 0;

        for(int i=n-1; i>=0; i--){
            for(int buy = 0; buy <= 1; buy++){
                int pick = 0, notPick = 0;
                if(buy == 1)
                    pick = max(-prices[i] + next[0], next[1]);
                else
                    notPick = max(prices[i] -fee + next[1], next[0]);
                curr[buy] = max(pick, notPick);
            }
            next = curr;

        }

        return  next[1];
    }
};
