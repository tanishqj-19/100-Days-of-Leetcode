class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        int mx = arr[n-1];
        for(int i=n-1; i>=0; i--){
            if(arr[i] > mx){
                swap(mx, arr[i]);
            }else
                arr[i] = mx;
            
            
            
        }
        arr[n-1] = -1;
        return arr;
    }
};
