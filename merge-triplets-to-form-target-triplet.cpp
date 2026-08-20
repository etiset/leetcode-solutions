class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> candidate(3);

        for(auto& triplet: triplets){
            bool valid = true;

            for(int i = 0; i < 3; i++){
                if(target[i] < triplet[i]){
                    valid = false;
                }
            }

            if(valid){
                for(int i = 0; i < 3; i++){
                    candidate[i] = max(candidate[i], triplet[i]);
                }
            }

            if(candidate == target){
                return true;
            }
        }

        return false;
    }
};