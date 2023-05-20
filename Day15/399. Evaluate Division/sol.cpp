class Solution {
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_map<string, bool> visited;
    double query;

    bool dfs(string start, string end, double product){

        if(start == end && adj.find(start) != adj.end()){
            query = product;
            return true;
        }

        visited[start] = true;
        bool temp = false;

        for(auto x: adj[start]){
            string v = x.first; double wt = x.second;

            if(!visited[v]){
                temp = dfs(v, end, product * wt);
                if(temp)
                    break;

            }
        }

        visited[start] = false;

        return temp;
    }
public:

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int n = equations.size();
        
        // adjacency list for weighted directed graph
        for(int i=0; i<n; i++){
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
            visited[equations[i][0]] = false;
            visited[equations[i][1]] =  false;
        }
        vector<double> ans(queries.size());


        for(int i=0; i<queries.size(); i++){
            query = 1;
            bool isPath = dfs(queries[i][0], queries[i][1], 1);
            if(isPath) 
                ans [i] = query;
            else
                ans[i] = -1;
        }

        return ans;
    }
};
