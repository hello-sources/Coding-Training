class Solution {
public:
    void backtracking(int start, int end) {
        if (start == end + 1) {
            cnt++;
            return; 
        } 
        for (auto &t : ans[start]) {
            if (temp[t]) continue;
            temp[t] = true;
            backtracking(start + 1, end);
            temp[t] = false;
        }
        return ;
    }

    int countArrangement(int n) {
        ans.resize(n + 1);
        temp.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i % j == 0 || j % i == 0) {
                    ans[i].emplace_back(j);
                }
            }
        }
        backtracking(1, n);
        return cnt;
    }

private:
    vector<vector<int>> ans;
    vector<bool> temp;
    int cnt;
};