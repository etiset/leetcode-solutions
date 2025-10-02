class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string s: strs){
            string t = s;
            sort(t.begin(), t.end());

            if(!mp.count(t)){
                mp[t] = vector<string>();
            }

            mp[t].push_back(s);
        }

        vector<vector<string>> res;

        for(auto it: mp){
            res.push_back(it.second);
        }

        return res;
    }
};