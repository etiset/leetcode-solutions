class Solution {
private:
    void backtrack(vector<string>& res, vector<char>& cand, int n, int op, int clrem){
        if(op == n && clrem == 0){
            string cand_str(cand.begin(), cand.end());
            res.push_back(cand_str);

            return;
        }

        if(op < n){
            cand.push_back('(');
            backtrack(res, cand, n, op + 1, clrem + 1);
            cand.pop_back();
        }

        if(clrem){
            cand.push_back(')');
            backtrack(res, cand, n, op, clrem - 1);
            cand.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> cand;

        backtrack(res, cand, n, 0, 0);

        return res;
    }
};