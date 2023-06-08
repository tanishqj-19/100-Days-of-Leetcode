class Solution {
    int solve(vector<int> &nums, int idx, vector<int> &dp){
        if(idx >= nums.size())
            return 0;
        if(dp[idx] != -1) return dp[idx];
        int j = idx+1;
        int currSum = nums[idx];
        while(j < nums.size() && nums[j] == nums[idx]){
            currSum += nums[idx];
            j++;
        }

        while(j < nums.size() && nums[j] == nums[idx] + 1)
            j++;
        
        return dp[idx] = max((currSum + solve(nums, j, dp)) ,solve(nums, idx + 1, dp));
        
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, -1);
        return solve(nums, 0, dp);
    }
};
