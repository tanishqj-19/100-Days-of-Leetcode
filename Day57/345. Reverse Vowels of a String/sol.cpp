class Solution {
public:
    string reverseVowels(string s) {
        string vowel = "";

        for(auto c: s){
            if(tolower(c)== 'a' || tolower(c)== 'e' || 
            tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) =='u')
                vowel += c;
        }

        string ans = "";
        int j = vowel.size()-1;
        
        for(int i=0; i<s.size(); i++){
            if(tolower(s[i])== 'a' || tolower(s[i])== 'e' || 
            tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) =='u')
                ans += vowel[j--];
            else
                ans += s[i];
        }
        return ans;
    }
};
