class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars(position.size());

        for(int i = 0; i < position.size(); i++){
            cars[i] = {position[i], (double) (target - position[i]) / speed[i]};
        }

        sort(cars.begin(), cars.end());

        int res = 1;
        int curr = position.size() - 1;

        for(int i = position.size() - 2; i >= 0; i--){
            if(cars[i].second > cars[curr].second){
                res++;
                curr = i;
            }
        }

        return res;
    }
};