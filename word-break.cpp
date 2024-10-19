class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> is_poss(s.size());

        for(int i = 0; i < s.size(); i++){
            bool found_match = false;

            for(string& word: wordDict){
                int len = word.size();
                int st = i - len + 1;

                if(st < 0){
                    continue;
                }

                if(st > 0 && is_poss[st-1] == false){
                    continue;
                }

                bool is_same = true;

                for(int j = 0; j < len; j++){
                    if(s[st + j] != word[j]){
                        is_same = false;
                        break;
                    }
                }

                if(is_same){
                    found_match = true;
                    break;
                }
            }

            if(found_match){
                is_poss[i] = true;
            }
        }

        return is_poss[s.size() - 1];
    }
};