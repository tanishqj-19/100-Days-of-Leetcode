class UndergroundSystem {
 
 unordered_map<int, pair<string, int>> check;
 unordered_map<string,pair<int, int>> stats;
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        check[id] = {stationName, t};
    }
    
    void checkOut(int id, string end, int timeOut) {
        auto & [start, timeIn] = check[id];
        
        auto& [total, cnt] = stats[start+ "->" + end];
        total += timeOut - timeIn;
        cnt++;

    }
    
    double getAverageTime(string startStation, string endStation) {
        auto& [total, cnt] = stats[startStation + "->" + endStation];

        return (double) total / cnt;
    }
};
