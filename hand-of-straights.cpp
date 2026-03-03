class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }

        sort(hand.begin(), hand.end());

        unordered_map<int, int> freqs;

        for(int card: hand){
            freqs[card]++;
        }

        for(int card: hand){
            if(freqs[card] > 0){
                for(int i = 0; i < groupSize; i++){
                    if(freqs[card + i] == 0){
                        return false;
                    }

                    freqs[card + i]--;
                }
            }
        }

        return true;
    }
};