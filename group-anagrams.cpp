class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ana_groups;

        for(string s: strs){
            string t = s;
            sort(t.begin(), t.end());

            if(ana_groups.count(t) == 0){
                ana_groups[t] = vector<string>();
            }

            ana_groups[t].push_back(s);
        }

        vector<vector<string>> res;

        for(auto& ana_group: ana_groups){
            res.push_back(ana_group.second);
        }

        return res;
    }
};