class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> seen;

        for(int i=0; i<s.size(); i++){
            seen[s[i]].first++;
            seen[s[i]].second = i;
        }
        int idx = s.size();
        for(auto [x, y] : seen){
            if(y.first == 1)
                idx = min(idx, y.second);
        }

        return idx  == s.size() ? -1 : idx;
    }
};
