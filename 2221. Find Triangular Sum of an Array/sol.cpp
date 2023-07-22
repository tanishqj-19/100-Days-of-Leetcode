class Solution {
public:
    int triangularSum(vector<int>& num) {
        int n = num.size();

        while(n > 1){
            for(int i=0; i<n-1; i++)
                num[i] = (num[i] + num[i+1]) % 10;
            n--;
        }

        return num[0];
    }
};
