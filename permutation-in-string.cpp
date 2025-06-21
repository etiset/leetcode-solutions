class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        auto getIndex = [](char c){ return c - 'a'; };

        const int n = 26;
        vector<int> m1(n), m2(n);

        for(char c: s1){
            m1[getIndex(c)]++;
        }

        int min_idx = s1.size() - 1;

        for(int i = 0; i < s2.size(); i++){
            m2[getIndex(s2[i])]++;

            if(i >= min_idx){
                if(m1 == m2){
                    return true;
                }

                int idx_to_remove = i - min_idx;
                m2[getIndex(s2[idx_to_remove])]--;
            }
        }

        return false;
    }
};