class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_set<string> u_set;
        unordered_map<int, unordered_map<string, int>> u_map;
        for (auto &x : orders) {
            u_set.insert(x[2]);
            int size = stoi(x[1]);
            u_map[size][x[2]]++;
        }
        vector<string> dish;
        for (auto &x : u_set) {
            dish.push_back(x);
        }
        sort(dish.begin(), dish.end());

        vector<int> tno;
        for (auto &[id, _] : u_map) {
            tno.push_back(id);
        }
        sort(tno.begin(), tno.end());
        vector<vector<string>> ans(u_map.size() + 1, vector<string>(u_set.size() + 1));
        ans[0][0] = "Table";
        for (int i = 0; i < dish.size(); i++) {
            ans[0][i + 1] = dish[i];
        }
        //copy(dish.begin(), dish.end(), ans[0].begin() + 1);
        for (int i = 0; i < u_map.size(); i++) {
            int id = tno[i];
            auto &cnt = u_map[id];
            ans[i + 1][0] = to_string(id);
            for (int j = 0; j < dish.size(); j++) {
                ans[i + 1][j + 1] = to_string(cnt[dish[j]]);
            }
        }
        return ans;
    }
};