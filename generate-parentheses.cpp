class Solution {
private:
    void findSolutions(vector<string>& res, vector<char>& curr, int oprem, int clrem){
        if(oprem == 0 && clrem == 0){
            res.push_back(string(curr.begin(), curr.end()));
            return;
        }

        if(oprem){
            curr.push_back('(');
            findSolutions(res, curr, oprem - 1, clrem + 1);
            curr.pop_back();
        }

        if(clrem){
            curr.push_back(')');
            findSolutions(res, curr, oprem, clrem - 1);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> curr;

        findSolutions(res, curr, n, 0);

        return res;
    }
};