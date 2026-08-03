class Solution {
private:
    void expandPalindrome(int st, int ed, string &s, vector<vector<bool>>& is_palindrome){
        while(st >= 0 && ed < s.size() && s[st] == s[ed]){
            is_palindrome[st--][ed++] = true;
        }
    }

    void extendPartition(int st, string& s, vector<vector<bool>>& is_palindrome, vector<vector<string>>& res, vector<string>& cand){
        if(st == s.size()){
            res.push_back(cand);
        }

        for(int ed = st; ed < s.size(); ed++){
            if(is_palindrome[st][ed]){
                cand.push_back(s.substr(st, ed-st+1));
                extendPartition(ed+1, s, is_palindrome, res, cand);
                cand.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> is_palindrome(s.size(), vector<bool>(s.size()));

        for(int i = 0; i < s.size(); i++){
            expandPalindrome(i, i, s, is_palindrome);
            expandPalindrome(i, i+1, s, is_palindrome);
        }

        vector<vector<string>> res;
        vector<string> cand;

        extendPartition(0, s, is_palindrome, res, cand);

        return res;
    }
};