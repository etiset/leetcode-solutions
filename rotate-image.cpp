class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int minv = 0;
        int maxv = matrix.size()-1;

        while(minv < maxv){
            vector<pair<int, int>> pts = {{minv, minv}, {minv, maxv}, {maxv, maxv}, {maxv, minv}};
            vector<pair<int, int>> movs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

            while(pts[0].second < maxv){
                for(int i = 1; i < 4; i++){
                    swap(matrix[pts[0].first][pts[0].second], matrix[pts[i].first][pts[i].second]);
                    pts[i].first += movs[i].first;
                    pts[i].second += movs[i].second;
                }

                pts[0].first += movs[0].first;
                pts[0].second += movs[0].second;
            }

            minv++;
            maxv--;
        }
    }
};