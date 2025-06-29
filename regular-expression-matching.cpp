class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> prev(p.size()+1);
        vector<bool> curr(p.size()+1);

        prev[0] = true;

        for(int i = 2; i < prev.size(); i += 2){
            prev[i] = prev[i-2] && p[i-1] == '*';
        }

        for(int i = 0; i < s.size(); i++){
            curr[0] = false;

            for(int j = 1; j < prev.size(); j++){
                if(p[j-1] == '*'){
                    curr[j] = curr[j-2];
                    bool cond1 = (p[j-2] == s[i]) || (p[j-2] == '.');
                    bool cond2 = prev[j];

                    if(cond1 && cond2){
                        curr[j] = true;
                    }

                    continue;
                }

                curr[j] = false;
                bool cond1 = (p[j-1] == s[i]) || (p[j-1] == '.');
                bool cond2 = prev[j-1];

                if(cond1 && cond2){
                    curr[j] = true;
                }
            }

            swap(prev, curr);
        }

        return prev.back();
    }
};