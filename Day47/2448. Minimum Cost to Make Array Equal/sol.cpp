
class Solution {
    long long solve(vector<int> &nums, vector<int> &cost, long long val){
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += abs(val-nums[i]) * cost[i];
        }
        return ans;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long val = 0, ans = 0;
        int n = nums.size();

        int left = INT_MAX, right = INT_MIN;

        for(auto & num: nums){
            left = min(num, left);
            right = max(num, right);
        }

        while(left < right){
            long mid = (left + right) / 2;

            long long y1 = solve(nums, cost, mid);
            long long y2 = solve(nums, cost, mid +1);
            ans = min(y1, y2);
            if(y1 < y2)
                right = mid;
            else
                left = mid +1;
        }

        return ans;
        
    }
};
