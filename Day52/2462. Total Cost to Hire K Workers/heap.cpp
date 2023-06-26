class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> mh1, mh2;

        int n  = costs.size();
        int count = 0, i = 0, j = n-1;

        while(count < k){
            count++;
            while(mh1.size() < candidates && i <= j){
                mh1.push(costs[i]);
                i++;
            }

            while(mh2.size() < candidates && j >= i){
                mh2.push(costs[j]); j--;
            }

            int n1 = INT_MAX, n2 = INT_MAX;
            if(mh1.size()){
                n1 = mh1.top(); 
            }
            if(mh2.size()){
                n2 = mh2.top(); 
            } 

            if(n1 <= n2){
                mh1.pop();
                ans += n1;
            }else{
                mh2.pop();
                ans += n2;
            }
            
        }

        return ans;
    }
};
