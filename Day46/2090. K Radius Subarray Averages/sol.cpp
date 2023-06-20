class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 2 * k +1;
        vector<long long> prefix(n+1, 0);
        vector<int> ans(n, -1);

        if(n < len)
            return ans;

        // Prefix Sum
        
        for(int i=0; i<n; i++){
            prefix[i+1]  = prefix[i] + nums[i];
            cout<<prefix[i+1]<<" ";
        }

        for(int i=k; i+k < n; i++){
            ans[i] = (prefix[i+k+1] - prefix[i-k]) / len;
        }
        return ans;

    }
};
