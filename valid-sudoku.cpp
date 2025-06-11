class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool res = true;

        for(int i = 0; i < 9; i++){
            bitset<9> bitrow;
            bitset<9> bitcol;
            
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(bitrow[board[i][j] - '0']){
                        return false;
                    }

                    bitrow[board[i][j] - '0'] = true;
                }

                if(board[j][i] != '.'){
                    if(bitcol[board[j][i] - '0']){
                        return false;
                    }

                    bitcol[board[j][i] - '0'] = true;
                }
            }
        }

        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                bitset<9> bit;

                for(int u = 0; u < 3; u++){
                    for(int v = 0; v < 3; v++){
                        int r = i + u;
                        int c = j + v;

                        if(board[r][c] != '.'){
                            if(bit[board[r][c] - '0']){
                                return false;
                            }

                            bit[board[r][c] - '0'] = true;
                        }
                    }
                }
            }
        }

        return res;
    }
};