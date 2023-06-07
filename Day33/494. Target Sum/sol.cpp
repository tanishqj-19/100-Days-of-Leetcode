class Solution {
    int findWays(vector<int> &nums, int sum, int i, vector<vector<int>> &dp){
        if(i == 0){
            if(sum == nums[0] && sum == 0)
                return 2;
            if(sum == 0 || sum == nums[0]) return 1;
            return 0;

        }
        if(dp[i][sum] != -1) return dp[i][sum];

        int take = 0;
        int nottake = findWays(nums, sum, i-1, dp);
        if(nums[i] <= sum)
            take = findWays(nums, sum-nums[i], i-1, dp);
        return dp[i][sum] = nottake + take;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totsum = 0;

        for(int &n: nums) totsum += n;

        int sum = (totsum-target);
        if(sum < 0 || sum % 2 != 0) return 0;
        sum/=2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return findWays(nums, sum, n-1, dp);

    }
};
