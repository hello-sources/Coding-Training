class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        for (int i = 0; i < m; i++) {
            deque<int> dq;
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*') dq.clear();
                else if (box[i][j] == '#') {
                    if (!dq.empty()) {
                        int ind = dq.front();
                        dq.pop_front();
                        box[i][ind] = '#';
                        box[i][j] = '.';
                        dq.push_back(j);
                    }
                } else dq.push_back(j);
            }
        }
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        return ans;
    }
};

/***********************模拟*********************/
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        for (int i = 0; i < m; i++) {
            int temp_ind = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    if (j != temp_ind) {
                        box[i][j] = '.';
                        box[i][temp_ind] = '#';
                    }
                    temp_ind--;
                } else if (box[i][j] == '*') {
                    temp_ind = j - 1;
                }
            }
        }
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        return ans;
    }
};