class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) minNum = min(minNum, num);
        for (auto str : bank) {
            int diff = 0;
            for (int i = 0; i < str.size(); i++) if (str[i] != start[i]) diff++;
            if (diff == 1 && u_set.find(str) == u_set.end()) {
                u_set.insert(str);
                num += 1;
                minMutation(str, end, bank);
                num -= 1;
                u_set.erase(str);
            }
        }
        return minNum == INT_MAX ? -1 : minNum;
    }
    
private :
    int minNum = INT_MAX, num = 0;
    unordered_set<string> u_set;
};