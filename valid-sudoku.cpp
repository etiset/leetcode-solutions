class Solution {
public:
    bool isValidString(string s){
        bitset<9> exists;

        for(char c: s){
            if(c != '.'){
                int idx = c - '1';

                if(exists[idx]){
                    return false;
                }

                exists[idx] = true;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool res = true;

        for(int i = 0; i < 9; i++){
            string s = ".........";

            for(int j = 0; j < 9; j++){
                s[j] = board[i][j];
            }

            res = (res && res == isValidString(s));
        }

        for(int i = 0; i < 9; i++){
            string s = ".........";

            for(int j = 0; j < 9; j++){
                s[j] = board[j][i];
            }

            res = (res && res == isValidString(s));
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                string a = string(board[3*i].begin() + (3*j), board[3*i].begin() + (3*j+3));
                string b = string(board[3*i+1].begin() + (3*j), board[3*i+1].begin() + (3*j+3));
                string c = string(board[3*i+2].begin() + (3*j), board[3*i+2].begin() + (3*j+3));
                string s = a + b + c;

                res = (res && res == isValidString(s));
            }
        }

        return res;
    }
};