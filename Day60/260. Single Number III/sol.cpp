class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int n: nums) mp[n]++;
        vector<int> ans;
        for(auto x: mp){
            if(x.second < 2) ans.push_back(x.first);

        }

        return ans;
    }
};
