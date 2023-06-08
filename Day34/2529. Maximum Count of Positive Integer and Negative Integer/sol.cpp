class Solution {
    int search(vector<int> &nums, int k){
        int l =0, r = nums.size();
        int mid;
        while(l < r){
            mid = l + (r-l) / 2;
            if(nums[mid] < k){
                l = mid + 1;
            }else
                r = mid;
        }
        return l;
    }
public:
    int maximumCount(vector<int>& nums) {
        int pos = nums.size() - search(nums, 1);
        int neg = search(nums, 0);
        
    
        return max(pos, neg);
    }
};
