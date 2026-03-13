class Solution {
private:
    int partition(int st, int ed, vector<int>& nums){
        int ridx = st + (rand() % (ed - st + 1));
        
        swap(nums[ed], nums[ridx]);
        int pivot = nums[ed];
        int leq_idx = st;

        for(int i = st; i < ed; i++){
            if(nums[i] < pivot){
                swap(nums[leq_idx++], nums[i]);
            }
        }

        swap(nums[leq_idx], nums[ed]);

        return leq_idx;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int st = 0;
        int ed = nums.size() - 1;
        k = nums.size() - k;

        while(st < ed){
            int m = partition(st, ed, nums);

            if(m == k){
                return nums[m];
            }

            else if(m < k){
                st = m + 1;
            }

            else{
                ed = m - 1;
            }
        }

        return nums[st];
    }
};