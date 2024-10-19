class Solution {
private:
    void extend_palindrome(string& s, vector<vector<bool>>& is_pal, int i, int j){
        while(i >= 0 && j < s.size()){
            if(s[i] != s[j]){
                return;
            }

            is_pal[i][j] = true;
            i--;
            j++;
        }
    }

    void backtrack(string& s, vector<vector<bool>>& is_pal, vector<string>& curr, vector<vector<string>>& res, int idx){
        if(idx == s.size()){
            res.push_back(curr);
        }

        for(int i = idx; i < s.size(); i++){
            if(is_pal[idx][i]){
                curr.push_back(s.substr(idx, i-idx+1));
                backtrack(s, is_pal, curr, res, i+1);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> is_pal(n, vector<bool>(n));

        for(int i = 0; i < n; i++){
            extend_palindrome(s, is_pal, i, i);
            extend_palindrome(s, is_pal, i, i + 1);
        }

        vector<string> curr;
        vector<vector<string>> res;

        backtrack(s, is_pal, curr, res, 0);

        return res;
    }
};