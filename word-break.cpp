class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> res(s.size() + 1);
        res[0] = true;

        for(int i = 1; i < res.size(); i++){
            for(string& word: wordDict){
                if(word.size() > i){
                    continue;
                }

                if(word == s.substr(i - word.size(), word.size())){
                    res[i] = res[i] || res[i - word.size()];
                }
            }
        }

        return res.back();
    }
};