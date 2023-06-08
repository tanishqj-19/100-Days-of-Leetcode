class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0, last = m-1;

        for(int i=0; i<n; i++){
            
            if(grid[i][0] < 0){
                count += m;
                continue;
            }
            
            if(grid[i][m-1] > 0) continue;

            int l = 0, r = last;

            while(l <= r){
                int mid = l + (r-l)/2;
                if(grid[i][mid] < 0)
                    r = mid-1;
                else 
                    l = mid + 1;
            }

            count += (m-l); last = l;
        }

        return count;
        
    }
};
