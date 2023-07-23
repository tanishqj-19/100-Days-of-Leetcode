class Solution {


    bool solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){

        if(j <= 0) return true;

        if(i <= 0) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1])
            return dp[i][j] = solve(s1, s2, i-1, j-1, dp);
        
        return dp[i][j] = solve(s1, s2, i-1, j, dp);
    }
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, -1));
        return solve(t, s, t.size(), s.size(), dp);
    }
};
