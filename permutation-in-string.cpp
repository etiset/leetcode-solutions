class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnts(26);

        for(char c: s1){
            cnts[c - 'a']++;
        }

        for(int i = 0; i < s2.size(); i++){
            if(i >= s1.size()){
                cnts[s2[i - s1.size()] - 'a']++;
            }

            cnts[s2[i] - 'a']--;

            if(all_of(cnts.begin(), cnts.end(), [](int x){ return x == 0; } )){
                return true;
            }
        }

        return false;
    }
};