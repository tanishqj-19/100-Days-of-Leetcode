class Solution {
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp){

        if(i < 0 && j < 0) return true; 
        if(i < 0 && j >= 0) return false;
        

        if(j < 0 & i >= 0){
            for(int idx = 0; idx <= i; idx++){
                if(p[idx] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return (bool)dp[i][j];

        if(p[i] == s[j] || p[i] == '?')
            return dp[i][j] = solve(s, p, i-1, j-1, dp);
        if(p[i] == '*')
            return dp[i][j] = solve(s, p, i-1, j, dp) || solve(s, p, i, j-1, dp);
        return false;
    
    }
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        
        return solve(s, p, n-1, m-1, dp);
    }
};
