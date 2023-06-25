class Solution {
    int mod = 1e9 + 7;

    int solve(vector<int> &loc, int fuel, int s, int f, vector<vector<int>> &dp){
        
        if(fuel < 0) 
            return 0;
        if(dp[s][fuel] != -1) return dp[s][fuel];
        long ans = 0;

        if(s == f)
            ans = 1;
        
        for(int next = 0; next < loc.size(); next++){
            if(next != s){
                ans  = (ans + solve(loc, fuel - abs(loc[next] - loc[s]), next, f, dp) % mod) % mod;
            }
        }

        return dp[s][fuel] = ans;

    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();

        vector<vector<int>> dp(n, vector<int>(fuel+1, -1));

        return solve(locations,fuel, start, finish, dp);
        
    }
};
