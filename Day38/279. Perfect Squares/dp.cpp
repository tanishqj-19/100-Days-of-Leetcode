class Solution {
public:
    int numSquares(int n) {
        if(n == 1 || n == 2 || n == 3)
            return n;
        if(n == 4)
            return 1;
        vector<int> arr;

        for(int i=1; i<n; i++){
            if(i * i <= n)
                arr.push_back(i*i);
        }
        vector<int> prev(n+1), curr(n+1);


        for(int i=0; i<=n; i++){
            if(i % arr[0] == 0)
                prev[i] =  i /arr[0];
            else
                prev[i] = 1e9;
        }

        for(int i=1; i<arr.size(); i++){
            for(int tar = 0; tar <= n; tar++){
                int notPick = prev[tar];
                int pick = 1e9;
                if(arr[i] <= tar)
                    pick = 1 + curr[tar-arr[i]];
                curr[tar] = min(pick, notPick); 
            }
            prev = curr;
        }
        return prev[n];
        
    }
};
