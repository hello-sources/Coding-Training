class MyCalendarThree {
public:
    map<int, int> res;
    MyCalendarThree() {}
    
    int book(int start, int end) {
        res[start] += 1;
        res[end] -= 1;
        int ans = 0, cur = 0;
        for (auto &[left, right] : res) {
            cur += right;
            ans = max(ans, cur);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */