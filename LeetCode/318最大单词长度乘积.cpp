class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        int ans = 0;
        for (int i = 0; i < len; i++) {
            unordered_map<char, int> u_map;
            for (auto &x : words[i]) u_map[x]++;
            for (int j = i + 1; j < len; j++) {
                bool flag = false;
                for (auto &x : words[j]) {
                    if (u_map[x] <= 0) continue;
                    flag = true;
                    break;
                }
                if (flag) continue;
                int size1 = words[i].size();
                int size2 = words[j].size();
                ans = max(ans, size1 * size2);
            }
        }
        return ans;
    }
};

/********************位运算**********************/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        int ans = 0;
        vector<int> masks(len);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                masks[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};