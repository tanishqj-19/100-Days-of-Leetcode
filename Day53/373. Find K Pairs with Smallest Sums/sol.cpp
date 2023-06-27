class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        priority_queue<pair<int, pair<int, int>>> maxheap;

        
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                long sum = nums1[i] + nums2[j];
                if(maxheap.size() < k){
                    maxheap.push({sum, {nums1[i], nums2[j]}});
                }else if(maxheap.top().first > sum){
                    maxheap.pop();
                    maxheap.push({sum, {nums1[i], nums2[j]}});
                }else
                    break;
            }
        }

        while(maxheap.size()){
            auto top = maxheap.top(); maxheap.pop();
            ans.push_back({top.second.first, top.second.second});
        }
        return ans;
    }
};
