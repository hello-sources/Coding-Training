class Solution {
public:
    void backtracking(vector<int> &materials, vector<vector<int>> &cookbooks, vector<vector<int>> &attribute, int limit, int ind) {
        if (limit <= 0) {
            ans.emplace_back(temp);
        }
        for (int i = ind; i < attribute.size(); i++) {
            bool flag = true;
            for (int j = 0; j < cookbooks[i].size(); j++) {
                if (materials[j] - cookbooks[i][j] < 0) flag = false;
            }
            if (!flag) continue;
            for (int j = 0; j < cookbooks[i].size(); j++) {
                materials[j] -= cookbooks[i][j];
            }
            temp.emplace_back(attribute[i]);
            backtracking(materials, cookbooks, attribute, limit - attribute[i][1], i + 1);
            temp.pop_back();
            for (int j = 0; j < cookbooks[i].size(); j++) {
                materials[j] += cookbooks[i][j];
            }
        }
        return ;
    }

    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
        backtracking(materials, cookbooks, attribute, limit, 0);
        int res = -1, cnt = 0;
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cnt += ans[i][j][0];
            }
            res = max(cnt, res);
            cnt = 0;
        }
        return res;
    }

private :
    vector<vector<int>> temp;
    vector<vector<vector<int>>> ans;
};