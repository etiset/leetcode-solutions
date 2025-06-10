class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> mp;

public:
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int r = point[0];
        int c = point[1];
        int res = 0;

        for(const auto& pts: mp[r]){
            int d = abs(c - pts.first);

            if(d > 0){
                res += pts.second * mp[r - d][c] * mp[r - d][pts.first];
                res += pts.second * mp[r + d][c] * mp[r + d][pts.first];
            }
        }

        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */