class MedianFinder {
public:
    priority_queue <int> los;
    priority_queue <int, vector<int>, greater<int>> his;

    MedianFinder() {
    }
    
    void addNum(int num) {
        los.push(num);
        his.push(los.top());
        los.pop();
        
        if(his.size() > los.size()){
            los.push(his.top());
            his.pop();
        }
    }
    
    double findMedian() {
        if(los.size() == his.size()){
            return (los.top() + his.top()) / 2.0;
        }

        return los.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */