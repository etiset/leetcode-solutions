class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> res(amount + 1, 0);
        res[0] = 1;

        for(int coin: coins){
            for(int i = coin; i <= amount; i++){
                // Included to address intermediate solution overflows.
                if(INT_MAX - res[i] < res[i-coin]){
                    break;
                }

                res[i] += res[i - coin];
            }
        }

        return res[amount];
    }
};