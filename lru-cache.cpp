class LRUCache {
private:
    int capacity_;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);

        if(it == cache.end()){
            return -1;
        }

        dll.splice(dll.begin(), dll, it -> second);

        return it -> second -> second;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        if(it != cache.end()){
            it -> second -> second = value;
            dll.splice(dll.begin(), dll, it -> second);

            return;
        }

        if(cache.size() == capacity_){
            int key_to_remove = dll.back().first;
            dll.pop_back();
            cache.erase(key_to_remove);
        }

        dll.emplace_front(key, value);
        cache[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */