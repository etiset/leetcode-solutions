class Solution {
private:
    pair<int, int> calculateCoordinates(int idx, int cols){
        return make_pair(idx/cols, idx%cols);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int lo = 0;
        int hi = n * m - 1;

        while(lo < hi){
            int midx = (lo + hi) / 2;
            auto [r, c] = calculateCoordinates(midx, m);

            if(matrix[r][c] < target){
                lo = midx + 1;
            }

            else{
                hi = midx;
            }
        }

        auto [r, c] = calculateCoordinates(lo, m);

        return matrix[r][c] == target;
    }
};