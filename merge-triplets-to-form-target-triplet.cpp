class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> curr(3);

        for(vector<int>& triplet: triplets){
            bool valid = true;

            for(int i = 0; i < 3; i++){
                if(max(triplet[i], curr[i]) > target[i]){
                    valid = false;
                }
            }

            if(valid){
                for(int i = 0; i < 3; i++){
                    curr[i] = max(triplet[i], curr[i]);
                }
            }
        }

        return (curr == target);
    }
};