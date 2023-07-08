class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> mp;

        for(int &n: nums)
            mp[n]++;
        for(auto & x: mp){
            if(x.second == 1){
                sum += x.first;

            }
        }

        return sum;

    }
}
