class Solution {

    int  solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        
        if(i == j) return nums[i];

        if(dp[i][j] != INT_MAX)return dp[i][j];
        return dp[i][j] = max(nums[i] - solve(nums, i+1, j, dp), nums[j] - solve(nums, i, j-1, dp));


    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));


        return solve(nums, 0, n-1, dp)>= 0;
    }
};
