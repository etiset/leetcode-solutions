class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st = 0;
        int ed = numbers.size() - 1;

        while(true){
            if(numbers[st] + numbers[ed] == target){
                break;
            }

            if(numbers[st] + numbers[ed] < target){
                st++;
            }

            else{
                ed--;
            }
        }

        return {st + 1, ed + 1};
    }
};