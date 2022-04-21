class Solution {
public:
    vector<int> ans;

    void dfs(int l, int r) {
        if (l > r) return ;
        ans.push_back(l);
        for (int i = 0; i <= 9; i++) {
            dfs(l * 10 + i, r);
        }
        return ;
    }

    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++) {
            dfs(i, n);
        }
        return ans;
    }
};

/*****************递推迭代*************/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int temp = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = temp;
            if (temp * 10 <= n) temp *= 10;
            else {
                while (temp % 10 == 9 || temp + 1 > n) {
                    temp /= 10;
                }
                temp++;
            }
        }
        return ans;
    }
};