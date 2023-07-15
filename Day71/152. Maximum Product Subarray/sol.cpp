class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0], mi = nums[0], ans = nums[0];

        for(int i = 1;i <nums.size(); i++){

            if(nums[i] < 0){
                int temp  = mi;
                mi = mx;
                mx = temp;
            }

            mx = max(nums[i], nums[i] * mx);
            mi = min(nums[i], nums[i] * mi);

            ans = max(ans, mx);
        }

        return ans;
    }
};
