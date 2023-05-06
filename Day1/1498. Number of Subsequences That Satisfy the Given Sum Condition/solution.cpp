class Solution {
    
public:
    int numSubseq(vector<int>& nums, int &target) {
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        int i=0, j = nums.size() -1, mod = 1e9 + 7;
        vector<int> pow(nums.size() + 1, 1);

        for(int i=1; i<=nums.size(); i++){
            pow[i] = (2* pow[i-1]) % mod;
        }

        while(i <= j){
            if(nums[i] + nums[j] <= target){
                ans = (ans + pow[j-i]) % mod;
                i++;
            }else
                j--;
        }
        return ans;
 
    }
};
