class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n = arr.size();
        unordered_map<int, int> dp;
        int ans = 1;
        for(int i=0; i<n; i++){
            dp[arr[i]] = 1 + dp[arr[i]-d];
            ans = max(ans,  dp[arr[i]]);
        }

        return ans;
    }
};
