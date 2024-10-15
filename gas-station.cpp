class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int st = 0;
        int net = 0;
        int curr = 0;

        for(int i = 0; i < n; i++){
            curr += gas[i] - cost[i];

            if(curr < 0){
                st = i + 1;
                net += curr;
                curr = 0;
            }
        }

        return (curr + net >= 0) ? st : -1;
    }
};