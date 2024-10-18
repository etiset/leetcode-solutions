class Solution {
private:
    bool findWord(vector<vector<char>>& board, string& word, int idx, int i, int j){
        if(word.size() == idx){
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n){
            return false;
        }

        if(word[idx] != board[i][j] || board[i][j] == '-'){
            return false;
        }

        char orig = board[i][j];
        board[i][j] = '-';

        bool res = findWord(board, word, idx+1, i+1, j) || findWord(board, word, idx+1, i-1, j)
                                                        || findWord(board, word, idx+1, i, j+1)
                                                        || findWord(board, word, idx+1, i, j-1);
        board[i][j] = orig;

        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(findWord(board, word, 0, i, j)){
                    return true;
                }
            }
        }

        return false;
    }
};