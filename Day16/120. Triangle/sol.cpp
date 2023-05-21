class Solution {
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n), curr(n);

        for(int i=0; i<n;i++)
            front[i] = triangle[n-1][i];
        for(int i = n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int same = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j+1];
                curr[j]= min(same, diag);
            }
            front = curr;
        }
        return  front[0];
         
    } 
}; 
