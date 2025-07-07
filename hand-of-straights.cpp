class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;

        for(int v: hand){
            mp[v]++;
        }

        for(auto it: mp){
            if(it.second == 0){
                continue;
            }

            int v = it.second;

            for(int i = 1; i < groupSize; i++){
                int cand = it.first + i;
        
                if(mp[cand] < v){
                    return false;
                }

                mp[cand] -= v;
            }
        }

        return true;
    }
};