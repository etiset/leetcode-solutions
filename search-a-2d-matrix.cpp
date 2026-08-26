class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        auto getCoordinates = [c](int idx){ return make_pair(idx/c, idx%c); };

        int st = 0;
        int ed = r * c - 1;

        while(st <= ed){
            int m = (st + ed) / 2;
            auto [x, y] = getCoordinates(m);

            if(matrix[x][y] == target){
                return true;
            }

            else if(matrix[x][y] < target){
                st = m + 1;
            }

            else{
                ed = m - 1;
            }
        }

        return false;
    }
};