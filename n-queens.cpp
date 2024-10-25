class Solution {
private:
    void generateBoard(vector<vector<string>>& res, vector<int>& config){
        vector<string> board(config.size(), string(config.size(), '.'));

        for(int i = 0; i < config.size(); i++){
            board[i][config[i]] = 'Q';
        }

        res.push_back(board);
    }

    bool isValidPlacement(vector<int>& config, int n, int ridx, int cidx){
        for(int r = 0; r < config.size(); r++){
            if(config[r] == cidx){
                return false;
            }

            int dy = ridx - r;
            int dx = abs(cidx - config[r]);

            if(dx == dy){
                return false;
            }
        }

        return true;
    }

    void placeQueen(vector<vector<string>>& res, vector<int>& config, int n, int ridx){
        if(ridx == n){
            generateBoard(res, config);
        }

        for(int i = 0; i < n; i++){
            if(isValidPlacement(config, n, ridx, i)){
                config.push_back(i);
                placeQueen(res, config, n, ridx+1);
                config.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> config;

        placeQueen(res, config, n, 0);

        return res;
    }
};