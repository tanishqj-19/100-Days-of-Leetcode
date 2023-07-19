class Solution {
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp){

        if(j <= 0)
            return 1;
        if(i <= 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i-1] == t[j-1]){
            return dp[i][j] = solve(s, t,i-1, j-1,dp) + solve(s, t, i-1, j, dp);
        }

        return dp[i][j] = solve(s, t, i-1, j, dp);
    }
public:
    int numDistinct(string &s, string &t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        return solve(s, t, s.size(), t.size(), dp);
    }
};
