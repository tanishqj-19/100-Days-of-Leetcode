class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m-1;


        while(row < n && col > -1){
            int curr = matrix[row][col];

            if(curr == target)
                return true;
            else if(curr > target){
                col--;
            }else
                row++;
        }

        return false;
    }
};
