class MedianFinder {
private:
    priority_queue<int> los_;
    priority_queue<int, vector<int>, greater<int>> his_;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(los_.empty()){
            los_.push(num);
            return;
        }

        if(los_.size() == his_.size()){
            int x = his_.top();
            his_.pop();

            los_.push(min(num, x));
            his_.push(max(num, x));

            return;
        }

        int x = los_.top();
        los_.pop();

        los_.push(min(num, x));
        his_.push(max(num, x));
    }
    
    double findMedian() {
        if(los_.size() == his_.size()){
            return (los_.top() + his_.top()) / 2.0;
        }

        return los_.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */