class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> pts;

public:
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        pts[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res = 0;

        int x = point[0];
        int y = point[1];

        for(auto [ny, cnt]: pts[x]){
            if(ny == y){
                continue;
            }

            int d = ny - y;

            for(int i = 0; i < 2; i++){
                int nx = x + d;

                res += cnt * pts[nx][y] * pts[nx][ny];

                d = -d;
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