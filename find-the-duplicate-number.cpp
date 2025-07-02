class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n1 = 0;
        int n2 = 0;

        while(true){
            n1 = nums[n1];
            n2 = nums[nums[n2]];

            if(n1 == n2){
                break;
            }
        }

        n1 = 0;
        
        while(n1 != n2){
            n1 = nums[n1];
            n2 = nums[n2];
        }

        return n1;
    }
};