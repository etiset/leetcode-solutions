class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res(nums.size() - k + 1);

        for(int i = 0; i < nums.size(); i++){
            if(!dq.empty() && dq.front() == i - k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i + 1 - k >= 0){
                res[i + 1 - k] = nums[dq.front()];
            }
        }

        return res;
    }
};