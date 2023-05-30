class Solution {
    int solve(vector<vector<int>> &grid, int i, int j1, int j2, int &n, int &m
        ,vector<vector<vector<int>>> &dp){

        if(j1 <0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e8;

        if(i == n-1){
            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1;
        for(int d1 = -1; d1 <=1; d1++){
            for(int d2 = -1; d2 <= 1; d2++){
                if(j1 == j2)
                    maxi = max(maxi, grid[i][j1] + solve(grid, i+1, j1 + d1, j2 + d2, n, m, dp));
                else
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(grid,i+1,j1+d1,j2+d2,n,m, dp));
            }
        }

        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(grid, 0, 0, m-1, n, m, dp);
    }
};
