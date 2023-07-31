class Solution {
    
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        long long sum1 =0, sum2 = 0;

        for(auto c: s1) sum1 += c;
        for(auto c: s2) sum2 += c;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1])
                    curr[j] = s1[i-1] + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }


        return sum1 + sum2 - 2 * prev[m];
    }
};
