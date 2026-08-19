class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        vector<int> frqs(26, 0);

        for(int i = 0; i < s.size(); i++){
            frqs[s[i] - 'a']++;
            frqs[t[i] - 'a']--;
        }

        return all_of(frqs.begin(), frqs.end(), [](int x){ return x == 0; });
    }
};