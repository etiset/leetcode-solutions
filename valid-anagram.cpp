class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        vector<int> cnts(26);

        for(int i = 0; i < s.size(); i++){
            cnts[s[i] - 'a']++;
            cnts[t[i] - 'a']--;
        }

        bool res = true;

        for(int i = 0; i < 26; i++){
            res = res && cnts[i] == 0;
        }

        return res;
    }
};