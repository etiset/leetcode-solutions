class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0){
            return false;
        }

        sort(hand.begin(), hand.end());

        unordered_map<int, int> cnts;

        for(int x: hand){
            cnts[x]++;
        }

        for(int x: hand){
            if(cnts[x]){
                for(int i = 0; i < groupSize; i++){
                    int idx = i + x;

                    if(cnts[idx] == 0){
                        return false;
                    }

                    cnts[idx]--;
                }
            }
        }

        return true;
    }
};