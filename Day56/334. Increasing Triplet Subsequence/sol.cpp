class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        int mini = INT_MAX, maxi = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i] <= mini)
                mini = nums[i];
            else if(nums[i] <= maxi)
                maxi = nums[i];
            else 
                return true;

        }

        return false;
    }
};
