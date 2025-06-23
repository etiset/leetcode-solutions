class Solution {
private:
    void findPalindromes(const string& s, vector<vector<bool>>& is_pal, int st, int ed){
        while(st >= 0 && ed < s.size()){
            if(s[st] != s[ed]){
                break;
            }

            is_pal[st--][ed++] = true;
        }
    }

    void findCombination(const string &s, const vector<vector<bool>> &is_pal, vector<vector<string>> &res, vector<int> &cand, int idx){
        if(idx == is_pal.size()){
            res.push_back(vector<string>(cand.size() - 1));

            for(int i = 1; i < cand.size(); i++){
                res.back()[i-1] = s.substr(cand[i-1], cand[i]-cand[i-1]);
            }

            return;
        }

        for(int i = idx+1; i <= is_pal.size(); i++){
            if(is_pal[idx][i-1]){
                cand.push_back(i);
                findCombination(s, is_pal, res, cand, i);
                cand.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> is_pal(s.size(), vector<bool>(s.size()));

        for(int i = 0; i < s.size(); i++){
            findPalindromes(s, is_pal, i, i);
            findPalindromes(s, is_pal, i, i+1);
        }

        vector<vector<string>> res;
        vector<int> cand = {0};

        findCombination(s, is_pal, res, cand, 0);

        return res;
    }
};