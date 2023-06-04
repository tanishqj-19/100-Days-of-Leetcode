class Solution {
    void dfs(vector<vector<int>> &adj, int node, unordered_map<int, bool> &visited){
        visited[node] = true;

        for(auto & nei: adj[node]){
            if(!visited[nei])
                dfs(adj, nei, visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        unordered_map<int, bool> visited;
        int c = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(adj, i, visited);
                c++;
            }
        }
        return c;
    }
};
