class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnts(26);

        for(char c: magazine){
            cnts[c - 'a']++;
        }

        for(char c: ransomNote){
            cnts[c - 'a']--;

            if(cnts[c - 'a'] < 0){
                return false;
            }
        }

        return true;
    }
};