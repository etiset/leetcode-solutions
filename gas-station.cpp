class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int neg_prefix = 0;

        int curr = 0;
        int curr_idx = 0;

        for(int i = 0; i < gas.size(); i++){
            curr += gas[i] - cost[i];

            if(curr < 0){
                neg_prefix += curr;
                curr = 0;
                curr_idx = i + 1;
            }
        }

        return (neg_prefix + curr >= 0) ? curr_idx : -1;
    }
};