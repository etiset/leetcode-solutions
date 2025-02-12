class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oc = image[sr][sc];
        int r = image.size();
        int c = image[0].size();

        vector<vector<int>> res(r, vector<int>(c, -1));

        vector<pair<int,int>> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> qu;

        qu.push(make_pair(sr, sc));
        res[sr][sc] = color;

        while(!qu.empty()){
            auto [u, v] = qu.front();
            qu.pop();

            for(auto [mu, mv]: movs){
                int nu = u + mu;
                int nv = v + mv;

                if(nu < 0 || nu == r || nv < 0 || nv == c){
                    continue;
                }

                if(image[nu][nv] == oc && res[nu][nv] == -1){
                    qu.push(make_pair(nu, nv));
                    res[nu][nv] = color;
                }
            }
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(res[i][j] == -1){
                    res[i][j] = image[i][j];
                }
            }
        }

        return res;
    }
};