class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        int prev = 1, prev2 = 1, prev3 = 0, ans = 0;
        for(int i=3; i<=n; i++){
            ans = prev3 + prev2 + prev;
            prev3 = prev2;
            prev2 = prev;
            prev = ans;
        }
        return ans;
    }
};
