class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int rid = 0;
        int cid = -1;
        int dir = 1;

        vector<int> res;

        while(rows && cols){
            for(int i = 0; i < cols; i++){
                cid += dir;
                res.push_back(matrix[rid][cid]);
            }

            rows--;

            for(int i = 0; i < rows; i++){
                rid += dir;
                res.push_back(matrix[rid][cid]);
            }

            cols--;
            dir = -dir;
        }

        return res;
    }
};