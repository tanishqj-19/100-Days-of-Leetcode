class SmallestInfiniteSet {
    set<int> s;
    int curr= 1;
public:
    SmallestInfiniteSet() {}
    
    int popSmallest() {
        if(s.empty()){
            return curr++;
        }else{
            int x = *s.begin();
            s.erase(x);
            return x;
        }
    }
    
    void addBack(int num) {
        if(curr> num)
            s.insert(num);
    }
};
