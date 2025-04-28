class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> cnts(amount+1, 0);
        cnts[0] = 1;

        for(int coin: coins){
            for(int i = coin; i <= amount; i++){
                if(INT_MAX - cnts[i] < cnts[i - coin]){
                    break;
                }
                
                cnts[i] += cnts[i - coin];
            }
        }

        return cnts[amount];
    }
};