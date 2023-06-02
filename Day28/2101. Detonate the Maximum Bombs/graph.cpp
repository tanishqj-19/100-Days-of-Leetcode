class Solution {

    void dfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited, int &node, int &c){

        visited[node] = true;
        c++;
        for(auto nei: adj[node]){
            if(!visited[nei]){
                dfs(adj, visited, nei, c);
            }
        }
        return;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++){
            long long r1 = bombs[i][2];
            for(int j=0; j<n; j++){
                if(i == j) continue;
                long long x2 = bombs[i][0] - bombs[j][0];
                long long y2 = bombs[i][1] - bombs[j][1];
                
                if((x2 * x2 + y2 * y2) <= r1 * r1)
                    adj[i].push_back(j);

            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int c = 0;
            unordered_map<int, bool> visited;
            dfs(adj, visited, i, c);
            ans = max(c, ans);
        }

        return ans;
    }
    
};
