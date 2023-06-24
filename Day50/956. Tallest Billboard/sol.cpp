class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = 0;
        for(int &num: rods) sum += num;

        vector<int> dp(sum+1, -1);
        dp[0] = 0;

        for(int rod: rods){
            vector<int> prev = dp;
            for(int i=0; i<= sum - rod; i++){
                if(prev[i] < 0) continue;

                dp[i + rod] =  max(dp[i+ rod], prev[i]);


                dp[abs(i - rod)] = max(dp[abs(i-rod)], prev[i] + min(i, rod));
            }
        }

        return dp[0];
    }
};
