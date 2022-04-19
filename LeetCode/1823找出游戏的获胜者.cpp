class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> que;
        for (auto x = 1; x <= n; x++) que.push(x);
        int ind = 1;
        while (que.size() != 1) {
            if (ind == k) {
                que.pop();
                ind = 1;
            } else {
                que.push(que.front());
                que.pop();
                ind++;
            }
        }
        return que.front();
    }
};

/************递归************/
class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) return 1;
        int ans = findTheWinner(n - 1, k) + k;
        return ans % n == 0 ? n : ans % n;
    }
};