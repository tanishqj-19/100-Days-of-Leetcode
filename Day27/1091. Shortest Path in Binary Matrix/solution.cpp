class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();


        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        q.push({0, 0});
        grid[0][0] = 1;

        while(!q.empty()){
            auto curr = q.front();
            int cx = curr.first , cy = curr.second;
            q.pop();
            if(cx == n-1 && cy == n-1) return grid[cx][cy];
            
            for(auto& dir: directions){
                int nx = cx + dir[0];
                int ny = cy + dir[1];
                
                if((nx >= 0 && nx < n) && (ny >= 0 && ny < n) && (grid[nx][ny] == 0)){
                    q.push({nx, ny});
                    grid[nx][ny] = grid[cx][cy] + 1;

                }
            }
        }

        return -1;
        
        
    }
};
