class Solution {
private:
    void findCombinations(int ops, int eds, vector<char> &candidate, vector<string> &res){
        if(ops == 0 && eds == 0){
            res.push_back(string(candidate.begin(), candidate.end()));
            return;
        }

        if(ops > 0){
            candidate.push_back('(');
            findCombinations(ops-1, eds+1, candidate, res);
            candidate.pop_back();
        }

        if(eds > 0){
            candidate.push_back(')');
            findCombinations(ops, eds-1, candidate, res);
            candidate.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> candidate;

        findCombinations(n, 0, candidate, res);

        return res;
    }
};