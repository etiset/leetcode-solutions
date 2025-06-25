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

        return all_of(cnts.begin(), cnts.end(), [](int x){ return x == 0; });
    }
};