class Solution {
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        queue<int> q;
        for(int src = 0; src < graph.size(); src++){

            if(color[src] == -1){
                color[src] = 1;
                
                q.push(src);

                while(!q.empty()){
                    int src = q.front(); q.pop();

                    for(auto nei: graph[src]){
                        if(color[nei] == -1){
                            color[nei] = 1 - color[src];
                            q.push(nei);
                        }
                        else
                            if(color[nei] == color[src])
                                return false;
                    }
                }
            }

            
        }
        return true;
    }
};
