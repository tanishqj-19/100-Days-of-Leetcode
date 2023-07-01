class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() < 2) return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        for(int n: nums){
            if(n != mini && n != maxi)
                return n;
        }
        return -1;
    }
};
