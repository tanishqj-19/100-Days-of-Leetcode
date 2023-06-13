class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> transpose(n, vector<int>(n));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                transpose[i][j] = grid[j][i];
        }
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j =0; j<n; j++)
                if(transpose[i] == grid[j])
                    ans++;
        }

        return ans;
    }
};
