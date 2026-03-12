class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> last_occ;

        for(int i = 0; i < s.size(); i++){
            last_occ[s[i]] = i;
        }

        vector<int> res;
        int st = 0;
        int ed = 0;

        for(int i = 0; i < s.size(); i++){
            ed = max(ed, last_occ[s[i]]);

            if(i == ed){
                res.push_back(ed - st + 1);
                st = ed + 1;
            }
        }

        return res;
    }
};