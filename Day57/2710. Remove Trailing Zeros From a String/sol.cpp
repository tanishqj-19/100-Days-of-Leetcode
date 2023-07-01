class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        int j = 0, i = n-1;

        while(i >= 0 && num[i] - '0'== 0){
            j++;
            i--;
        }

        return num.substr(0, n-j);

    }
};
