class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int curr_min = 100000;

        for(int x: prices){
            res = max(res, x - curr_min);
            curr_min = min(curr_min, x);
        }

        return res; 
    }
};