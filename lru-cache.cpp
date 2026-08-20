class LRUCache {
private:
    int capacity_;
    list<pair<int, int>> dll_;
    unordered_map<int, list<pair<int, int>>::iterator> cache_;

public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        auto it = cache_.find(key);

        if(it == cache_.end()){
            return -1;
        }

        dll_.splice(dll_.begin(), dll_, it -> second);

        return cache_[key] -> second;
    }

    void put(int key, int value) {
        if(cache_.count(key)){
            dll_.erase(cache_[key]);
            cache_.erase(key);
        }
        
        else if(cache_.size() == capacity_){
            int cacheKey = dll_.back().first;
            
            dll_.pop_back();
            cache_.erase(cacheKey);
        }

        dll_.emplace_front(key, value);
        cache_[key] = dll_.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */