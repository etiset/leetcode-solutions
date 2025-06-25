class Solution {
private:
int partition(vector<int> &nums, int lo, int hi){
    int ridx = lo + rand() % (hi - lo + 1);
    swap(nums[ridx], nums[hi]);
    
    int pivot = nums[hi];
    int leq_idx = lo;

    for(int j = lo; j < hi; j++){
        if(nums[j] < pivot){
            swap(nums[leq_idx++], nums[j]);
        }
    }

    swap(nums[leq_idx], nums[hi]);

    return leq_idx;
}

public:
    int findKthLargest(vector<int>& nums, int k) {
        int lo = 0;
        int hi = nums.size() - 1;
        k = nums.size() - k;

        while(lo < hi){
            int idx = partition(nums, lo, hi);

            if(idx == k){
                return nums[idx];
            }

            else if(idx <= k){
                lo = idx + 1;
            }

            else{
                hi = idx - 1;
            }
        }

        return nums[lo];
    }
};