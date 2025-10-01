class Solution {
private:
    void processCombination(int op, int cl, vector<string> &res, vector<char> &curr){
        if(op == 0 && cl == 0){
            res.push_back(string(curr.begin(), curr.end()));
        }

        if(op > 0){
            curr.push_back('(');
            processCombination(op-1, cl+1, res, curr);
            curr.pop_back();
        }

        if(cl > 0){
            curr.push_back(')');
            processCombination(op, cl-1, res, curr);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> curr;

        processCombination(n, 0, res, curr);

        return res;
    }
};