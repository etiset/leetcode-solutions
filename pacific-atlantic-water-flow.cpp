class Solution {
private:
    vector<pair<int, int>> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void floodFill(int r, int c, int v, vector<vector<int>>& heights, vector<vector<int>>& reached){
        reached[r][c] |= v;

        for(auto [dr, dc]: movs){
            int nr = r + dr;
            int nc = c + dc;

            if(nr < 0 || nr == heights.size() || nc < 0 || nc == heights[0].size()){
                continue;
            }
            
            if((reached[nr][nc] & v) == 0 && heights[r][c] <= heights[nr][nc]){
                floodFill(nr, nc, v, heights, reached);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> reached(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            floodFill(i, 0, 1, heights, reached);
        }

        for(int i = 0; i < n; i++){
            floodFill(0, i, 1, heights, reached);
        }

        for(int i = 0; i < m; i++){
            floodFill(i, n-1, 2, heights, reached);
        }

        for(int i = 0; i < n; i++){
            floodFill(m-1, i, 2, heights, reached);
        }

        vector<vector<int>> res;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(reached[i][j] == 3){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};