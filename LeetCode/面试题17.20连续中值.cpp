class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> prq1;
    priority_queue<int, vector<int>, greater<int>> prq2;
    MedianFinder() {}
    
    void addNum(int num) {
        prq1.push(num);
        while (prq2.size() > 0 && prq1.top() > prq2.top()) {
            prq2.push(prq1.top());
            prq1.pop();
        }
        while (prq1.size() > prq2.size() + 1 || prq1.size() < prq2.size()) {
            if (prq1.size() > prq2.size() + 1) {
                prq2.push(prq1.top());
                prq1.pop();
            } else {
                prq1.push(prq2.top());
                prq2.pop();
            }
        }
        return ;
    }
    
    double findMedian() {
        return prq1.size() == prq2.size() ? ((double)prq1.top() + (double)prq2.top()) / 2 : (double)prq1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */