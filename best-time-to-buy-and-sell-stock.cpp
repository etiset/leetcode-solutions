class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int max_to_right = -1;

        for(int i = prices.size()-2; i >= 0; i--){
            max_to_right = max(max_to_right, prices[i+1]);

            int cand = max(0, max_to_right - prices[i]);
            res = max(res, cand);
        }

        return res;
    }
};