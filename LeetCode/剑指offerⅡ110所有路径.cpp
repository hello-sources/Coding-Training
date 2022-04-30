class Solution {
public:
    void backtracking(int ind, int end, vector<vector<int>> &graph) {
        if (ind == end) {
            ans.emplace_back(temp);
            return ;
        }
        for (auto &m : graph[ind]) {
            temp.emplace_back(m);
            backtracking(m, end, graph);
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        temp.emplace_back(0);
        backtracking(0, n - 1, graph);
        return ans;
    }

private :
    vector<vector<int>> ans;
    vector<int> temp;
};