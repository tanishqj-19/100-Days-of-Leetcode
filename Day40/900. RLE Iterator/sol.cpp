class RLEIterator {
    vector<int> vec;
    int curr;
public:
    RLEIterator(vector<int>& encoding) {
        curr = 0;
        vec = encoding;
    }
    
    int next(int n) {
        while(curr < vec.size()){
            if(vec[curr] >= n){
                vec[curr] -= n;
                return vec[curr + 1];
            }else{
                n -= vec[curr];
                curr += 2;
            }
        }
        return -1;
    }
};
