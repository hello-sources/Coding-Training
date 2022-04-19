class MyCalendar {
public:
    map<int, int> cnt;
    MyCalendar() {}
    
    bool book(int start, int end) {
        cnt[start] += 1;
        cnt[end] -= 1;
        int cur = 0;
        for (auto &[left, right] : cnt) {
            cur += right;
            if (cur > 1) {
                cnt[start]--;
                cnt[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */