class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <2)
            return nums.size();
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 1;

        for(int &n: nums){

            // in case of duplicates
            if(set.find(n) == set.end()) continue;

            set.erase(n);
            int prev = n-1, next = n+1;

            while(set.find(prev) != set.end()) set.erase(prev--);
            while(set.find(next) != set.end()) set.erase(next++);
            ans = max(ans, next-prev-1);
        }

        return ans;
            
        
    }
};
