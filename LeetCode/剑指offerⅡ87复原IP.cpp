class Solution {
public:
    bool judge(string &s, int start, int end) {
        if (start > end) return false;
        if (s[start] == '0' && start != end) return false;
        int num = 0;
        for (int i = start; i <= end; i++) {
            num *= 10;
            num += s[i] - '0';
            if (num > 255) return false;
        }
        return true;
    }

    void backtracking(string &s, int ind, int cnt) {
        if (cnt == 3 && judge(s, ind, s.size() - 1)) {
            ans.emplace_back(s);
        }
        for (int i = ind; i < s.size(); i++) {
            if (!judge(s, ind, i)) break;
            s.insert(s.begin() + i + 1, '.');
            cnt++;
            backtracking(s, i + 2, cnt);
            cnt--;
            s.erase(s.begin() + 1 + i);
        }
        return ;
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 15) return ans;
        backtracking(s, 0, 0);
        return ans;
    }

private :
    vector<string> ans;
};