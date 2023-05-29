class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<int> prev(n, 1e9);
        for(int j=0; j<n; j++)
            prev[j] = matrix[0][j];
        
        for(int i=1; i<n; i++){
            vector<int> curr(n);
            for(int j=0; j<n;j++){
                int ans= INT_MAX;
                for(int k = 0; k<matrix.size(); k++){
                    if(j == k) continue;
                    ans  = min(ans, matrix[i][j] + prev[k]);
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        int mini = 1e9;
        for(int j=0; j<n; j++)
            mini = min(mini, prev[j]);
        
        return mini;
    }
};
