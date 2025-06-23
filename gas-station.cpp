class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0;
        int tot = 0;
        int curr = 0;

        for(int i = 0; i < gas.size(); i++){
            curr += gas[i] - cost[i];

            if(curr < 0){
                res = i + 1;
                tot += curr;
                curr = 0;
            }
        }

        return (curr + tot >= 0) ? res : -1;
    }
};