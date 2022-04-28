class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> proc(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                proc[i][preferences[i][j]] = j;
            }
        }
        vector<int> match(n);
        for (auto pair : pairs) {
            match[pair[0]] = pair[1];
            match[pair[1]] = pair[0];
        }
        int cnt = 0;
        for (int x = 0; x < n; x++) {
            int y = match[x];
            int ind = proc[x][y];
            for (int i = 0; i < ind; i++) {
                int u = preferences[x][i];
                int v = match[u];
                if (proc[u][x] < proc[u][v]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};