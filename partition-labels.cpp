class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_occ;

        for(int i = 0; i < s.size(); i++){
            last_occ[s[i]] = i;
        }

        vector<int> res;

        for(int i = 0; i < s.size();){
            int st = i;
            int ed = last_occ[s[i]];

            while(i <= ed){
                ed = max(ed, last_occ[s[i]]);
                i++;
            }

            res.push_back(ed - st + 1);
        }

        return res;
    }
};