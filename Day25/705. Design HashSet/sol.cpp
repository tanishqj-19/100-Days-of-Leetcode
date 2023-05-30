class MyHashSet {
    vector<bool> arr;
public:
    MyHashSet() : arr(1e6+1, false) {}
    
    void add(int key) {
        arr[key] = true;
    }
    
    void remove(int key) {
        arr[key] = false;
    }
    
    bool contains(int key) {
        return arr[key];
    }
};
