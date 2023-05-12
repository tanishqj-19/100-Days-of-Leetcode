class Solution {
    
    long long getPoint(int idx,vector<vector<int>>& questions, vector<long long> &dp){
        
        if(idx == questions.size() - 1)
            return questions[idx][0];
        if(idx >= questions.size())
            return 0;
        if(dp[idx] != 0) return dp[idx];
        
        long long pick = questions[idx][0] + getPoint(idx + questions[idx][1] + 1, questions, dp);
        long long drop = 0 + getPoint(idx + 1, questions, dp);

        return dp[idx] = max(pick, drop);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size(), 0);
        return getPoint(0, questions, dp);
    }
};
