class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(int row, int col, vector<vector<bool>> &ocean, vector<vector<int>> &heights) {
        int m = ocean.size();
        int n = ocean[0].size();
        if (ocean[row][col]) return ;
        ocean[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int newrow = row + dirs[i][0], newcol = col + dirs[i][1];
            if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n && heights[newrow][newcol] >= heights[row][col]) {
                dfs(newrow, newcol, ocean, heights);
            }
        }
        return ;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) dfs(i, 0, pacific, heights);
        for (int j = 1; j < n; j++) dfs(0, j, pacific, heights);
        for (int i = 0; i < m; i++) dfs(i, n - 1, atlantic, heights);
        for (int j = 0; j < n - 1; j++) dfs(m - 1, j, atlantic, heights);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    vector<int> cell;
                    cell.push_back(i);
                    cell.push_back(j);
                    ans.emplace_back(cell);
                }
            }
        }
        return ans;
    }

private :
    vector<vector<int>> ans;
};