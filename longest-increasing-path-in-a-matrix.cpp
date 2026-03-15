class Solution {
private:
    const vector<pair<int, int>> movs_ = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int findSolution(const vector<vector<int>> &matrix, vector<vector<int>> &max_path, int r, int c){
        if(max_path[r][c] != -1){
            return max_path[r][c];
        }

        int rows = max_path.size();
        int cols = max_path[0].size();

        int& res = max_path[r][c];
        res = 1;

        for(auto it: movs_){
            int nr = r + it.first;
            int nc = c + it.second;

            if(nr < 0 || nr == rows || nc < 0 || nc == cols){
                continue;
            }

            if(matrix[r][c] > matrix[nr][nc]){
                int cand = 1 + findSolution(matrix, max_path, nr, nc);
                res = max(res, cand);
            }
        }

        return res;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> max_path(rows, vector<int>(cols, -1));

        int res = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int cand = findSolution(matrix, max_path, i, j);
                res = max(res, cand);
            }
        }

        return res;
    }
};