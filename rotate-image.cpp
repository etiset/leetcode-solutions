class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<pair<int, int>> corns{{0, 0}, {0, n-1}, {n-1, n-1}, {0, n-1}};
        vector<pair<int, int>> movs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int i = 0; true; i++){
            int st = i;
            int ed = n-1-i;

            if(st >= ed){
                break;
            }

            vector<pair<int, int>> norns{{st, st}, {st, ed}, {ed, ed}, {ed, st}};

            for(int j = 0; j < ed - st; j++){
                pair<int, int>& ul = norns[0];
                pair<int, int>& ur = norns[1];
                pair<int, int>& br = norns[2];
                pair<int, int>& bl = norns[3];

                swap(matrix[ul.first][ul.second], matrix[ur.first][ur.second]);
                swap(matrix[ul.first][ul.second], matrix[br.first][br.second]);
                swap(matrix[ul.first][ul.second], matrix[bl.first][bl.second]);

                for(int k = 0; k < 4; k++){
                    norns[k].first += movs[k].first;
                    norns[k].second += movs[k].second;
                }
            }
        }
    }
};