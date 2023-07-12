class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, bool> mp;
        for(auto c: sentence)
            mp[c] = true;
        for(int i=0; i<26;i++){
            if(!mp[i+ 'a'])
                return false;
        }

        return true;
    }
};
