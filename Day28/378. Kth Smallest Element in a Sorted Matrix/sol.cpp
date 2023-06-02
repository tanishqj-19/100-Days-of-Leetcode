class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>, vector<vector<int>> , greater<>> minHeap;

        for(int i=0; i<min(n, k); i++){
            minHeap.push({matrix[i][0], i, 0});
        }
        int ans;

        for(int i=1; i<=k;i++){
            auto top = minHeap.top(); minHeap.pop();
            int row = top[1], col = top[2];
            ans = top[0];
            if(col + 1 < n) minHeap.push({matrix[row][col+1], row, col+1});
        }

        return ans;
    }
};
