class Solution {
 
public:
    bool canPartition(vector<int>& nums) {
        // Calculate sum
        int sum = 0;
        for(auto & n: nums)
            sum += n;
        // Check if sum is even or odd if it's odd we can't divide it into 2 subsets
        if(sum % 2 != 0)
            return false;
        // Since our target sum is half of the whole array sum
        sum /= 2;
        
        int n = nums.size();
       vector<bool> prev(sum+1, false);
        // Since at sum = 0 all index will be true
        for(int i=0; i<n; i++){
            prev[0] = true;
        }

        if(nums[0] <= sum)
            prev[nums[0]] = true;
        // i=1 Since we already set values for i=0
        for(int i=1; i<n; i++){
            vector<bool>curr (sum+1, 0);
            for(int target=1; target <= sum; target++){
                // 2 cases either we take an element or we don't take an element
                bool take = false;
                bool notTake = prev[target];
                // if we take the remaining sum will be sum - nums[i] value
                if(nums[i] <= target){
                    take = prev[target-nums[i]];
                }
                // Either of the condition is true that's our answer;
                curr[target] = notTake || take;
            }
            prev = curr;
        }
        return prev[sum];
    }
};
