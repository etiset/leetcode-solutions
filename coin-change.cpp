class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxx = amount + 5;

        vector<int> cnt(amount + 1, maxx);
        cnt[0] = 0;

        for(int coin: coins){
            for(int i = coin; i <= amount; i++){
                cnt[i] = min(cnt[i], cnt[i - coin] + 1);
            }
        }

        return (cnt[amount] < maxx) ? cnt[amount] : -1;
    }
};