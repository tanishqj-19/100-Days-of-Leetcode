class Solution {
    
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long> prev(amount+1, 0), curr(amount+1, 0);

        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0)
                prev[i] = 1;
        }

        for(int i=1; i<n; i++){
            for(int sum = 0; sum<=amount; sum++){
                long notPick = prev[sum];
                long pick = 0;
                if(coins[i] <= sum)
                    pick = curr[sum-coins[i]];

                curr[sum] = pick + notPick;
            }
            prev = curr;
        }
        return (int) prev[amount];
    }
};
