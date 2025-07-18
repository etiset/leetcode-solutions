class KthLargest {
private:
    int k_;
    priority_queue<int, vector<int>, greater<int>> pq_;

public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;

        for(int x: nums){
            add(x);
        }
    }
    
    int add(int val) {
        if(pq_.size() == k_ && pq_.top() < val){
            pq_.pop();
            pq_.push(val);
        }

        else if(pq_.size() < k_){
            pq_.push(val);
        }

        return pq_.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */