class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            int rmsk = 0;
            int cmsk = 0;

            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int val = 1 << (board[i][j] - '.');

                    if(rmsk & val){
                        return false;
                    }

                    rmsk |= val;
                }

                if(board[j][i] != '.'){
                    int val = 1 << (board[j][i] - '.');

                    if(cmsk & val){
                        return false;
                    }

                    cmsk |= val;
                }
            }
        }

        for(int r = 0; r < 9; r += 3){
            for(int c = 0; c < 9; c += 3){
                int msk = 0;

                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(board[r+i][c+j] == '.'){
                            continue;
                        }

                        int val = 1 << (board[r+i][c+j] - '.');

                        if(msk & val){
                            return false;
                        }
 
                        msk |= val;
                    }
                }
            }
        }

        return true;
    }
};