class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0;
        int prev1 = 0;

        for(int i = 2; i <= cost.size(); i++){
            int curr = prev2 + cost[i-2];
            curr = min(curr, prev1 + cost[i-1]);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};