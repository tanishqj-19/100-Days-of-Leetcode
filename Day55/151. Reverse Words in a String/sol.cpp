class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int i = 0, j = 0, n = s.size(), last = 0;

        while(j < n){
            while(j < n && s[j] == ' ') j++;

            int start = i;
            while(j < n && s[j] != ' '){
                s[i++] = s[j++];
                last = i;
            }
            reverse(s.begin() + start, s.begin() + i);
            s[i++] = ' ';
        }

        s.resize(last);
        return s;
    }
};
