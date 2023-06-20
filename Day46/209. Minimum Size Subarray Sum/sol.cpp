class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        int idx = INT_MAX;
        long long sum = 0;

        while(r < n){
            sum +=  nums[r++];
            while(sum >= target){
                idx = min(r-l, idx);
                sum -= nums[l++];

            }
        }

        if(idx == INT_MAX)
            return 0;

        return idx;
    }
};
