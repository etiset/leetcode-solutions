class Solution {
private:
    vector<pair<int, int>> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void floodFill(int r, int c, char ochr, char nchr, vector<vector<char>>& board){
        board[r][c] = nchr;

        for(auto& [dr, dc]: movs){
            int nr = r + dr;
            int nc = c + dc;

            if(nr < 0 || nr == board.size() || nc < 0 || nc == board[0].size()){
                continue;
            }

            if(board[nr][nc] == ochr){
                floodFill(nr, nc, ochr, nchr, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                floodFill(i, 0, 'O', 'B', board);
            }

            if(board[i][n - 1] == 'O'){
                floodFill(i, n - 1, 'O', 'B', board);
            }
        }

        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                floodFill(0, i, 'O', 'B', board);
            }

            if(board[m - 1][i] == 'O'){
                floodFill(m - 1, i, 'O', 'B', board);
            }
        }

        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(board[i][j] == 'O'){
                    floodFill(i, j, 'O', 'X', board);
                }
            }
        }

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'B'){
                floodFill(i, 0, 'B', 'O', board);
            }

            if(board[i][n - 1] == 'B'){
                floodFill(i, n - 1, 'B', 'O', board);
            }
        }

        for(int i = 0; i < n; i++){
            if(board[0][i] == 'B'){
                floodFill(0, i, 'B', 'O', board);
            }

            if(board[m - 1][i] == 'B'){
                floodFill(m - 1, i, 'B', 'O', board);
            }
        }
    }
};