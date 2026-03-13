class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> prev = {0, -prices[0], 0};
        vector<int> curr(3);

        for(int i = 1; i < prices.size(); i++){
            curr[0] = max(prev[0], prev[2]);
            curr[1] = max(prev[0] - prices[i], prev[1]);
            curr[2] = prev[1] + prices[i];

            swap(prev, curr);
        }

        return *max_element(prev.begin(), prev.end());
    }
};