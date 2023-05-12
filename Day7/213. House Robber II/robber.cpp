class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n  = nums.size();
        if(n == 1) return nums[0];
        int prev1 = nums[0], prev2 = 0, curr;
        

        for(int i=1; i<n-1; i++){
            
            curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;

        }

        int p1 = nums[1], p2 = 0;

        for(int i = 2; i<n; i++){
            curr = max(nums[i] + p2, p1);
            p2 = p1;
            p1 = curr;
        }

        return max(p1, prev1);
    }
};
