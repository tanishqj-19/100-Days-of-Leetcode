class SnapshotArray {
    int snap_id = 0;
    unordered_map<int, map<int, int>> mp;
public:
    SnapshotArray( int length) {
        for(int i=0; i<length; i++){
            map<int, int> temp;
            temp[0] = 0;
            mp[i] = temp;
        }
    }
    
    void set( int index,  int val) {
        mp[index][snap_id] = val;
        
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        
        auto it = mp[index].upper_bound(snap_id); it--;
        return it->second;

    }
};
