class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n  = nums.size(),  ans = 2;

        vector<unordered_map<int, int>> dp(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int d = nums[j] - nums[i];
                if(dp[j].count(d)){
                    dp[i][d] = dp[j][d] + 1;
                }else
                    dp[i][d] = 2;
                ans = max(dp[i][d], ans);
            }
        }

        return ans;
    }
};
