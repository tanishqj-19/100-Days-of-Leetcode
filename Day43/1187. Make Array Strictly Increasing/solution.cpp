class Solution {
    int solve( map<pair<int, int>, int>& mp, vector<int> &arr1, vector<int> &arr2, 
    int i, int prev){
        if(i >= arr1.size())
            return 0;
        if(mp.find({i,prev})!=mp.end())
            return mp[{i,prev}];
        int ans = INT_MAX/2;

        int f=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        if(arr1[i]>prev)
            ans=min(ans, solve(mp, arr1, arr2, i+1, arr1[i]));
        if(f<arr2.size())
            ans=min(ans,solve(mp, arr1, arr2, i+1, arr2[f]) + 1);
        return mp[{i,prev}]=ans;
        
    
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n  = arr1.size(), m = arr2.size();
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>, int> mp;
        
        int ans = solve(mp, arr1, arr2, 0, INT_MIN);

        if(ans >= INT_MAX / 4)
            return -1;
        

        return ans;
    }
};
