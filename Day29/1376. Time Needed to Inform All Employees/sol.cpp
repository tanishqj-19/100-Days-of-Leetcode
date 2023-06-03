class Solution {

    int dfs(vector<int> & informTime, vector<int> &manager, int node){
        if(manager[node] != -1){
            informTime[node] += dfs(informTime,manager, manager[node]);
            manager[node] = -1;
        }

        return informTime[node];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        int ans = 0;

        for(int i=0; i<n; i++){
            ans = max(ans, dfs(informTime, manager, i));
        }

        return ans;

    }
};
