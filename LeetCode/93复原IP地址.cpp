class Solution {
public:
    bool judge(string s, int l, int r) {
        if (l > r) return false;
        if (s[l] == '0' && l != r) return false;
        int num = 0;
        for (int i = l; i <= r; i++) {
            num = num * 10 + s[i] - '0';
            if (num > 255) return false;
        }
        return true;
    }

    void backtracking(string s, int ind, int cnt) {
        if (cnt == 3 && judge(s, ind, s.size() - 1)) {
            ans.emplace_back(s);
        } 
        for (int i = ind; i < s.size(); i++) {
            if (!judge(s, ind, i)) break;
            s.insert(s.begin() + i + 1, '.');
            cnt++;
            backtracking(s, i + 2, cnt);
            cnt--;
            s.erase(s.begin() + i + 1);
        }
        return ;
    }

    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return ans;
    }

private :
    vector<string> ans;
};