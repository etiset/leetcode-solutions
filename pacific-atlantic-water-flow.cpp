class Solution {
private:
    void bfs(const vector<vector<int>>& heights, vector<vector<bool>>& visited, queue<pair<int, int>> qu){
        vector<pair<int, int>> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int r = heights.size();
        int c = heights[0].size();

        while(!qu.empty()){
            auto [u, v] = qu.front();
            qu.pop();

            for(const auto &mov: movs){
                int nu = u + mov.first;
                int nv = v + mov.second;

                if(nu < 0 || nu == r || nv < 0 || nv == c){
                    continue;
                }

                if(!visited[nu][nv] && heights[u][v] <= heights[nu][nv]){
                    visited[nu][nv] = true;
                    qu.push({nu, nv});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        vector<vector<bool>> pacific(r, vector<bool>(c));
        vector<vector<bool>> atlantic(r, vector<bool>(c));

        queue<pair<int, int>> qu_pacific;
        queue<pair<int, int>> qu_atlantic;

        for(int i = 0; i < r; i++){
            pacific[i][0] = true;
            atlantic[i][c-1] = true;

            qu_pacific.push({i, 0});
            qu_atlantic.push({i, c-1});
        }
        
        for(int i = 0; i < c; i++){
            pacific[0][i] = true;
            atlantic[r-1][i] = true;

            qu_pacific.push({0, i});
            qu_atlantic.push({r-1, i});
        }

        bfs(heights, pacific, qu_pacific);
        bfs(heights, atlantic, qu_atlantic);

        vector<vector<int>> res;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};