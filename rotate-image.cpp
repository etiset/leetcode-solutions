class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int minv = 0;
        int maxv = matrix[0].size() - 1;

        while(minv < maxv){
            for(int offset = 0; offset < maxv - minv; offset++){
                vector<pair<int, int>> pts = {
                    {minv, minv + offset},
                    {minv + offset, maxv},
                    {maxv, maxv - offset},
                    {maxv - offset, minv}
                };

                for(int i = 1; i < 4; i++){
                    swap(matrix[pts[0].first][pts[0].second], matrix[pts[i].first][pts[i].second]);
                }
            }

            minv++;
            maxv--;
        }
    }
};