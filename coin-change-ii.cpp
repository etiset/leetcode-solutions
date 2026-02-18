class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> res(amount + 1);
        res[0] = 1;

        for(int coin: coins){
            for(int i = coin; i < res.size(); i++){
                if(INT_MAX - res[i] > res[i - coin]){
                    res[i] += res[i - coin];
                }
            }
        }

        return res.back();
    }
};