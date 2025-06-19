class Solution {
private:
    inline pair<int, int> getCoordinates(int idx, int col){
        return make_pair(idx / col, idx % col);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        int minn = 0;
        int maxx = r * c - 1;

        while(minn < maxx){
            int m = (minn + maxx) >> 1;
            auto [mr, mc] = getCoordinates(m, c);

            if(matrix[mr][mc] < target){
                minn = m + 1;
            }

            else{
                maxx = m;
            }
        }

        auto [mr, mc] = getCoordinates(minn, c);
        return (matrix[mr][mc] == target);
    }
};