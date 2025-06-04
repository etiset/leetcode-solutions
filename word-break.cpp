class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> valid(s.size() + 1);
        valid[0] = true;

        for(int i = 1; i <= s.size(); i++){
            for(string& word: wordDict){
                if(i < word.size()){
                    continue;
                }

                int st = i - word.size();

                if(!valid[st]){
                    continue;
                }

                bool are_same = true;

                for(int j = 0; j < word.size(); j++){
                    if(word[j] != s[st + j]){
                        are_same = false;
                        break;
                    }
                }

                if(are_same){
                    valid[i] = true;
                    break;
                }
            }
        }
        
        return valid[s.size()];
    }
};