class Solution {
private:
    bool findWord(vector<vector<char>>& board, const string& word, int r, int c, int idx){
        if(r < 0 || r == board.size() || c < 0 || c == board[0].size()){
            return false;
        }

        if(board[r][c] != word[idx]){
            return false;
        }

        if(idx == word.size() - 1){
            return true;
        }

        char val = board[r][c];
        board[r][c] = '-';

        bool res = findWord(board, word, r+1, c, idx+1);
        res = res || findWord(board, word, r, c+1, idx+1);
        res = res || findWord(board, word, r-1, c, idx+1);
        res = res || findWord(board, word, r, c-1, idx+1);

        board[r][c] = val;
        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(findWord(board, word, i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};