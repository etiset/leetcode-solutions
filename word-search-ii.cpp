struct TrieNode {
    vector<TrieNode*> children {vector<TrieNode*>(26)};
    string word {""};
};

class Solution {
private:
    void insertWord(TrieNode* root, const string &word){
        TrieNode* curr = root;

        for(char c: word){
            int idx = c - 'a';

            if(curr -> children[idx] == nullptr){
                curr -> children[idx] = new TrieNode();
            }

            curr = curr -> children[idx];
        }

        curr -> word = word;
    }

    void searchWord(vector<string> &res, vector<vector<char>>& board, TrieNode* root, int r, int c){
        int idx = board[r][c] - 'a';

        if(root -> children[idx] == nullptr){
            return;
        }

        root = root -> children[idx];

        if(root -> word.size()){
            res.push_back(root -> word);
            root -> word.clear();
        }

        char val = board[r][c];
        board[r][c] = '#';

        for(auto mov: movs_){
            int nr = r + mov.first;
            int nc = c + mov.second;

            if(nr < 0 || nr == board.size() || nc < 0 || nc == board[0].size()){
                continue;
            }

            if(board[nr][nc] != '#'){
                searchWord(res, board, root, nr, nc);
            }
        }
        
        board[r][c] = val;
    }

    vector<pair<int, int>> movs_ = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = new TrieNode();

        for(auto &word: words){
            insertWord(root, word);
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                searchWord(res, board, root, i, j);
            }
        }

        return res;
    }
};