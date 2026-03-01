class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int ridx = 0;
        int cidx = -1;
        int dir = 1;

        vector<int> res;

        while(rows && cols){
            for(int i = 0; i < cols; i++){
                cidx += dir;
                res.push_back(matrix[ridx][cidx]);
            }

            rows--;

            for(int i = 0; i < rows; i++){
                ridx += dir;
                res.push_back(matrix[ridx][cidx]);
            }

            cols--;
            dir = -dir;
        }

        return res;
    }
};