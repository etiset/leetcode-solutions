class TimeMap {
private:
    unordered_map<string, map<int, string>> mp;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][-timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)){
            return "";
        }

        auto it = mp[key].lower_bound(-timestamp);
        
        return (it == mp[key].end()) ? "" : it -> second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */