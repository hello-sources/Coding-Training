class Solution {
public:
    int clumsy(int n) {
        stack<int> sta;
        sta.push(n);
        n--;
        int ind = 0;
        while (n) {
            if (ind % 4 == 0) sta.top() *= n;
            else if (ind % 4 == 1) sta.top() /= n;
            else if (ind % 4 == 2) sta.push(n);
            else sta.push(-n);
            ind++;
            n--;
        }
        int sum = 0;
        while (!sta.empty()) {
            sum += sta.top();
            sta.pop();
        }
        return sum;
    }
};