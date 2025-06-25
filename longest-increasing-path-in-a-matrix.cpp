class Solution {
private:
    int findSolution(const vector<vector<int>> &matrix, vector<vector<int>> &mpath, int r, int c){
        if(mpath[r][c] != -1){
            return mpath[r][c];
        }

        int rows = mpath.size();
        int cols = mpath[0].size();
        auto isValidCell = [rows, cols](int r, int c){ return r >= 0 && r < rows && c >= 0 && c < cols; };

        int res = 1;

        for(auto it: movs_){
            int nr = r + it.first;
            int nc = c + it.second;

            if(isValidCell(nr, nc) && matrix[r][c] > matrix[nr][nc]){
                res = max(res, 1 + findSolution(matrix, mpath, nr, nc));
            }
        }

        return mpath[r][c] = res;
    }

    const vector<pair<int, int>> movs_ = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> mpath(rows, vector<int>(cols, -1));

        int res = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                res = max(res, findSolution(matrix, mpath, i, j));
            }
        }

        return res;
    }
};