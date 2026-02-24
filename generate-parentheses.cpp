class Solution {
private:
    void extendCombination(int ops, int cls, vector<string>& res, vector<char>& cand){
        if(ops == 0 && cls == 0){
            res.push_back(string(cand.begin(), cand.end()));
        }

        if(ops > 0){
            cand.push_back('(');
            extendCombination(ops-1, cls+1, res, cand);
            cand.pop_back();
        }

        if(cls > 0){
            cand.push_back(')');
            extendCombination(ops, cls-1, res, cand);
            cand.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> cand;

        extendCombination(n, 0, res, cand);

        return res;
    }
};