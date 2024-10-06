class DetectSquares {
private:
    int max_grid_len = 1001;
    unordered_map<int, vector<int>> points;
    unordered_map<int, int> hash_count;

public:
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int point_hash = max_grid_len*x+y;

        if(points.count(x) == 0){
            points[x] = vector<int>();
            hash_count[point_hash] = 0;
        }

        points[x].push_back(y);
        hash_count[point_hash]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int res = 0;

        vector<int> signs = {1, -1};

        for(int v: points[x]){
            int len = abs(y - v);

            if(len == 0){
                continue;
            }

            for(int sign: signs){
              int a_hash = max_grid_len*(x+sign*len)+y;
              int b_hash = max_grid_len*(x+sign*len)+v;

              if(hash_count.count(a_hash) && hash_count.count(b_hash)){
                res += hash_count[a_hash] * hash_count[b_hash];
              }
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