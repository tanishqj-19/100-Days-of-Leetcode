class Solution {
    int solve(vector<int> &coins, int amount, int i, vector<vector<int>> &dp){

        if(i == 0){
            if(amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9;
        }
        
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int take =  1e9;

        int nottake = solve(coins, amount, i-1, dp);
        if(coins[i] <= amount)
            take  = 1 + solve(coins, amount-coins[i], i, dp);

        return dp[i][amount] = min(take, nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));

        int ans = solve(coins, amount, coins.size() -1, dp);
        if(ans == 1e9) return -1;
        return ans;

    }
};
