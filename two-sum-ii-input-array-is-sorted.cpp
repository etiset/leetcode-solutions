class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lidx = 0;
        int ridx = numbers.size() - 1;

        while(true){
            int s = numbers[lidx] + numbers[ridx];

            if(s == target){
                break;
            }

            if(s < target){
                lidx++;
            }

            if(s > target){
                ridx--;
            }
        }

        return {lidx+1, ridx+1};
    }
};