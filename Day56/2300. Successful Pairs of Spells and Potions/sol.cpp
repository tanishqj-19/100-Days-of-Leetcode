class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = spells.size(), m = potions.size();


        sort(potions.begin(), potions.end());

        for(int i=0; i<n; i++){
            int l = 0, h = m-1;
            int mid;

            while(l <= h){
                mid = (l+h) / 2;
                long long check = (long)spells[i] * (long)potions[mid];

                if(check >= success)
                    h = mid-1;
                else
                    l = mid + 1;

                
            }
            ans.push_back(m-h-1);
        }

        return ans;
    }
};
