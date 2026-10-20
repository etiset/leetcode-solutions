class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> res(s.size() + 1);
        res[0] = true;

        for(int i = 1; i <= s.size(); i++){
            for(string& word: wordDict){
                if(i < word.size()){
                    continue;
                }

                if(!res[i - word.size()]){
                    continue;
                }

                if(word == s.substr((i-1)-(word.size()-1), word.size())){
                    res[i] = true;
                    break;
                }
            }
        }

        return res.back();
    }
};