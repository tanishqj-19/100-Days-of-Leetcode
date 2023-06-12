class Solution{
    int solve(int i, int W, int val[], int wt[], vector<vector<int>> &dp){
        
        if(i == 0){
            return (int) (W / wt[0]) * val[0];
        }
        
        if(dp[i][W] != -1)
            return dp[i][W];
        
        int pick = 0;
        int notPick = solve(i-1, W, val, wt, dp);
        if(wt[i] <= W)
            pick = val[i] + solve(i, W-wt[i], val, wt, dp);
        return dp[i][W] = max(pick, notPick);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
       vector<vector<int>> dp(N, vector<int>(W+1, -1));
       
       return solve(N-1, W, val, wt, dp);
    }
};
