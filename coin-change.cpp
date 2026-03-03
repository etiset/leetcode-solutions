class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount + 1, INT_MAX);
        res[0] = 0;

        for(int coin: coins){
            for(int i = coin; i < res.size(); i++){
                if(res[i - coin] != INT_MAX){
                    res[i] = min(res[i], res[i - coin] + 1);
                }
            }
        }

        return (res.back() == INT_MAX ? -1 : res.back());
    }
};