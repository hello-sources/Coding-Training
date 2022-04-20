class cmp {
public :
    bool operator()(const pair<string, int> &a, const pair<string, int> &b) {
        return b.second > a.second;
    }
};

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> u_set;
        unordered_map<string, int> u_map;
        for (auto &str : banned) u_set.insert(str);
        string s;
        for (auto &str : paragraph) {
            if (isalpha(str)) {
                s.push_back(tolower(str));
            } else if (s.size() > 0){
                if (!u_set.count(s)) u_map[s]++;
                s = "";
            }
        }
        // unordered_map<string, int>::iterator iter = max_element(u_map.begin(), u_map.end(), cmp());
        // return iter->first;
        int max = 0;
        for (auto &[k, v] : u_map) {
            if (v > max) {
                max = v;
                s = k;
            }
        }
        return s;
    }
};