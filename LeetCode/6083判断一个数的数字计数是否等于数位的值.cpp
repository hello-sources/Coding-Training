class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> u_map;
        for (auto ch : num) {
            u_map[ch - '0']++;
        } 
        for (int i = 0; i < num.size(); i++) {
            if (u_map[i] != num[i] - '0') return false;
        }
       return true;
    }
};