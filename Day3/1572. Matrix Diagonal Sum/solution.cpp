class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, n = mat.size();

        for(int i=0; i<n; i++){
            if(i != n-i-1) sum += mat[i][i] + mat[i][n-i-1];
            else sum += mat[i][i];
        }
        return sum;
    }
};


// Brute Force
// class Solution {
// public:
//     int diagonalSum(vector<vector<int>>& mat) {
//         int sum = 0 ;
//         int n = mat.size(), m = mat[0].size();

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(i == j || i+j == n-1){
//                     sum += mat[i][j];
//                 }
//             }
//         }

//         return sum;
//     }
// };
