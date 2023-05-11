class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int first0 = edges[0][0], second0 = edges[1][0]
        ,first1 = edges[0][1], second1 = edges[1][1];

        if(first0 == second0 || first0 == second1)
            return first0;
        else
            // since Graph contains a center
            return first1;
    }
};
