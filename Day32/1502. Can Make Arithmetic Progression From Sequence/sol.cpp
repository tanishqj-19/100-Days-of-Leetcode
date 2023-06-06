class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size() <= 2) return true;
        unordered_set<int> seen;
        int mini = INT_MAX, maxi = INT_MIN;

        for(int& num: arr){
            mini = min(mini, num); maxi = max(maxi, num);
            seen.insert(num);
        }
        int d = maxi - mini, n = arr.size();
        if(d % (n-1) != 0) return false;
        d /= (n-1);

        while(--n>0){
            if(seen.find(mini) == seen.end()) return false;
            mini += d;
        }
        return true;
    }
};
