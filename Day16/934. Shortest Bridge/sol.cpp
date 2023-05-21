class Solution {
    queue<pair<int, int>> q;

    void dfs(vector<vector<int>> &grid, int i, int j){
        if(i < 0 || i >= grid.size() || j <0 || j >= grid.size() || 
            grid[i][j] == 2 || grid[i][j] == 0)
            return;
        grid[i][j] = 2;
        q.push({i, j});
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int bfs(vector<vector<int>> &grid){
         
        int dist = 0;
        int minDis = INT_MAX;

        vector<vector<int>> direction = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        while(!q.empty()){
            int n = q.size();
            while(n-- > 0){
                auto x = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int a = direction[i][0] + x.first;
                    int b = direction[i][1] + x.second;

                    if(a >= 0 && a < grid.size() && b >=0 && b < grid.size() && grid[a][b] == 1)
                        minDis = min(minDis, dist);
                    else if(a >= 0 && a < grid.size() && b >=0 && b<grid[0].size() && grid[a][b] == 0){
                        q.push({a, b});
                        grid[a][b] = 2;
                    }
                
                }       
            }
            dist++;
        }

        return minDis;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n  = grid.size();

         bool flag = false;
        
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 1 and !flag){
                    dfs(grid, i, j); 
                    q.push({i,j});
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        
        return bfs(grid);
    }
};
