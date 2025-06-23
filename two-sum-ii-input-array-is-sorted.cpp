class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0;
        int hi = numbers.size() - 1;

        while(lo < hi){
            while(lo < hi && numbers[lo] + numbers[hi] > target){
                hi--;
            }

            if(numbers[lo] + numbers[hi] == target){
                break;
            }

            lo++;
        }

        return {lo+1, hi+1};
    }
};