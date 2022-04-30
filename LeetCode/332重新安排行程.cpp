class Solution {
public:
    bool backtracking(int cnt, vector<string> &ans) {
        if (cnt + 1 == ans.size()) return true;
        for (auto &target : targets[ans[ans.size() - 1]]) {
            if (target.second <= 0) continue;
            ans.emplace_back(target.first);
            target.second--;
            if (backtracking(cnt, ans)) return true;
            ans.pop_back();
            target.second++;
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &ticket : tickets) {
            targets[ticket[0]][ticket[1]]++;
        }
        ans.emplace_back("JFK");
        backtracking(tickets.size(), ans);
        return ans;
    }

private:
    vector<string> ans;
    unordered_map<string, map<string, int>> targets;
};