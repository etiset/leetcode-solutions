class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> cnts;

        for(int c: p){
            cnts[c]++;
        }

        int st = 0;
        int cmatched = 0;

        vector<int> res;

        for(int ed = 0; ed < s.size(); ed++){
            int ced = s[ed];

            if(cnts.count(ced)){
                cnts[ced]--;

                if(cnts[ced] == 0){
                    cmatched++;
                }
            }

            if(ed < p.size() - 1){
                continue;
            }

            if(cmatched == cnts.size()){
                res.push_back(st);
            }

            int cst = s[st];

            if(cnts.count(cst)){
                cnts[cst]++;

                if(cnts[cst] == 1){
                    cmatched--;
                }
            }
            
            st++;
        }

        return res;
    }
};