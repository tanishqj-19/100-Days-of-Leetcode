class Solution {

    int solve(vector<vector<int>>&mat, int i, int j, vector<vector<int>> &dp){
        
        if(j < 0 || j >= mat.size())
            return 1e9;
        if(i == 0)
            return mat[0][j];
        if(dp[i][j] != 1e9)
            return dp[i][j];
        int ld = mat[i][j] + solve(mat, i-1, j-1, dp);
        int rd = mat[i][j] + solve(mat, i-1, j+1, dp);
        int up = mat[i][j] + solve(mat, i-1, j, dp);

        return dp[i][j] = min(ld, min(rd, up));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, 1e9));
        int ans = 1e9;
        for(int j=0; j<n; j++){
            int temp = solve(matrix, n-1, j, dp);
            ans = min(ans, temp);
        }
        
        return ans;
    }
};
