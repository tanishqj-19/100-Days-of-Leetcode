class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> spiral_matrix;
        
        int row_start = 0, col_start = 0, row_end = matrix.size() - 1, col_end = matrix[0].         size()-1;

        while(row_start <= row_end && col_start  <=col_end){

            for(int col = col_start; col <= col_end ; col++)
                spiral_matrix.push_back(matrix[row_start][col]);
            row_start++;

            for(int row = row_start; row <= row_end; row++)
                spiral_matrix.push_back(matrix[row][col_end]);
            col_end--;

            for(int col = col_end; col >=  col_start && row_start <= row_end; col--)
                spiral_matrix.push_back(matrix[row_end][col]);
            
            row_end--;

            for(int row = row_end; row>= row_start && col_start <= col_end; row--)
                spiral_matrix.push_back(matrix[row][col_start]);
            col_start++;    

        }
        return spiral_matrix;
        
    }
};
