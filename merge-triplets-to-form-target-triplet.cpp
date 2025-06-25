class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> curr(3);

        for(const auto &it: triplets){
            bool valid = true;

            for(int i = 0; i < 3; i++){
                if(target[i] < it[i]){
                    valid = false;
                    break;
                }
            }

            if(valid){
                for(int i = 0; i < 3; i++){
                    curr[i] = max(curr[i], it[i]);
                }
            }
        }

        return (curr == target);
    }
};