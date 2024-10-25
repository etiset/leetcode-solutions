class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rid = 0;
        int cid = -1;

        int dir = 1;

        vector<int> res;

        int m = matrix.size();
        int n = matrix[0].size();

        while(m && n){
            for(int i = 0; i < n; i++){
                cid += dir;
                res.push_back(matrix[rid][cid]);
            }
            m--;

            for(int i = 0; i < m; i++){
                rid += dir;
                res.push_back(matrix[rid][cid]);
            }
            n--;

            dir *= -1;
        }

        return res;
    }
};