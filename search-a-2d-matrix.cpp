class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        auto getCoordinates = [c](int idx){ return make_pair(idx / c, idx % c); };

        int st = 0;
        int ed = r * c - 1;

        while(st <= ed){
            int m = (st + ed) / 2;
            auto [u, v] = getCoordinates(m);

            if(matrix[u][v] == target){
                return true;
            }

            if(matrix[u][v] > target){
                ed = m - 1;
            }

            else{
                st = m + 1;
            }
        }

        return false;
    }
};