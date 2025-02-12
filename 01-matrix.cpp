class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<pair<int, int>> movs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>> qu;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    res[i][j] = 0;
                    qu.push(make_pair(i, j));
                }
            }
        }

        while(!qu.empty()){
            auto [u, v] = qu.front();
            qu.pop();

            for(auto mov: movs){
                int nu = u + mov.first;
                int nv = v + mov.second;

                if(nu < 0 || nv < 0 || nu == m || nv == n){
                    continue;
                }

                if(res[nu][nv] == -1){
                    res[nu][nv] = res[u][v] + 1;
                    qu.push(make_pair(nu, nv));
                }
            }
        }

        return res;
    }
};