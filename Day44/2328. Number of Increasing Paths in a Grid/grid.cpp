class Solution {
    int mod = 1000000007; 
    int solve(vector<vector<int>>& grid, int i, int j, int prev,vector<vector<int>> &dp){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= prev)
            return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int left = solve(grid, i, j-1, grid[i][j], dp) % mod;
        int right = solve(grid, i, j+1, grid[i][j], dp) % mod;
        int up = solve(grid, i-1, j, grid[i][j], dp) % mod;
        int down = solve(grid, i+1, j, grid[i][j], dp) % mod;

        return dp[i][j] = 1 + (left + right) % mod + (up +down) % mod;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int paths = 0;
        for(int i=0;i <n; i++){
            for(int j=0; j<m; j++){
                if(dp[i][j] == -1)
                    paths  = (paths + solve(grid, i, j, -1, dp)) % mod;
                else
                    paths  = (paths % mod+ dp[i][j] % mod) % mod;
            }
        }

        return paths;
    }
};
