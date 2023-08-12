class Solution {
    int solve(vector<vector<int>>& obs, int i, int j, vector<vector<int>>& dp){
        if(i >=0 && j >= 0 && obs[i][j] == 1)
            return 0;
        if(i < 0 || j<0) return 0;
        if(i == 0 && j == 0) return 1;

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = solve(obs,i-1, j, dp);
        int left = solve(obs, i, j-1, dp);

        return dp[i][j] = up + left;


    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size(), n = obs[0].size();
        vector<int> prev(n, 0);
        
        for(int i=0; i<m; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                
                
                if(i >= 0 && j >= 0 && obs[i][j] ==1) {
                    curr[j] = 0;
                    continue;
                }
                if(i == 0 && j == 0){
                    curr[j] = 1;
                    continue;
                }

                int up = 0, left = 0;
                
                if(i > 0)
                    up = prev[j];
                if(j > 0)
                    left = curr[j-1];
                
                curr[j] = up + left;

            }
            prev = curr;
        }

        return prev[n-1];
        
    }
};
