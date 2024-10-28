class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars(position.size());

        for(int i = 0; i < cars.size(); i++){
            cars[i].first = position[i];
            cars[i].second = (double) (target - position[i]) / speed[i];
        }

        sort(cars.begin(), cars.end());

        int res = 1;
        int curr_idx = cars.size() - 1;

        for(int i = cars.size() - 2; i >= 0; i--){
            if(cars[i].second > cars[curr_idx].second){
                res++;
                curr_idx = i;
            }
        }

        return res;
    }
};