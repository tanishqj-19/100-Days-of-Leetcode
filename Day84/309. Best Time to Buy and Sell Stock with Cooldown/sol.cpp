class Solution {
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0), next(2, 0), nextTonext(2, 0);

        for(int i = n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                if(buy == 1)
                    curr[buy] = max(-prices[i] + next[0],
                                next[1]);
                else
                    curr[buy] = max(prices[i] + nextTonext[1], 
                                next[0]);

            }
            nextTonext = next;
            next = curr;
        }


        return next[1];
    }
};
