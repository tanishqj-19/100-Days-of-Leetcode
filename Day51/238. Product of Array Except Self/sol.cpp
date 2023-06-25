class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1;
        vector<int> ans(nums.size(), 0);
        int c = 0;

        bool  flag = 0;
        long nonZero = 0;
        for(int i: nums){
            if(i == 0) c++;
            product *= i;

            if(i != 0){
                if(flag == 0){
                    nonZero = 1;
                    flag = 1;
                }
                nonZero *= i;
            }
                
        }
        if(c >= 2)
            return ans;

        for(int i=0; i<nums.size(); i++){
            
            if(nums[i] != 0){
                ans[i] = product / nums[i];
            }else{
                ans[i] = nonZero;
            }
        }

        return ans;
    }
};
