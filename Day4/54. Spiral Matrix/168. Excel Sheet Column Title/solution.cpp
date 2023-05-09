class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;

        char c;

        while(columnNumber){
            columnNumber -=1;
            c = 'A' + columnNumber % 26;
            ans = c + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};
