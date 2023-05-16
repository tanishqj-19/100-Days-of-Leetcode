class Solution {
public:
    int minDays(vector<int>& bloom, int m, int k) {
        int n = bloom.size();
        if((long)k * m > n) return -1;

        int s = INT_MAX, e = INT_MIN;

        for(auto &x: bloom){
            s = min(x, s);
            e = max(x, e);
        }
        while(s < e){
            int mid = (s + e) / 2, count = 0, bouq = 0;

            for(int i=0; i<n; i++){
                if(bloom[i] > mid)
                    count = 0;
                else if(++count >= k){
                    bouq++;
                    count = 0;
                }
            }

            if(bouq < m){
                s = mid + 1;
            }else
                e = mid;


        }

        return s;

    }
};
