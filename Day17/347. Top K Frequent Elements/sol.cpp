class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        for(auto &n: nums) mp[n]++;

        vector<vector<int>> bucket(nums.size() + 1);

        for(auto &it: mp){
            bucket[it.second].push_back(it.first);
        }
        
        vector<int> ans;
        for(int i = bucket.size() - 1; i>=0 && ans.size() < k; i--){

            for(int num: bucket[i]){
                ans.push_back(num);
                if(ans.size() == k)
                    break;
            }

        }

        return ans;
  
    }
};
