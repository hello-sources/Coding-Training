class MyCalendarTwo {
public:
    map<int, int> cnt;
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        cnt[start] += 1;
        cnt[end] -= 1;
        int cur = 0;
        for (auto &[left, right] : cnt) {
            cur += right;
            if (cur > 2) {
                cnt[start]--;
                cnt[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */