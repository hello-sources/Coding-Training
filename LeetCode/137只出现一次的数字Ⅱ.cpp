class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> u_map;
        for (auto &x : nums) u_map[x]++;
        for (auto &[k, v] : u_map) {
            if (v == 1) return k;
        }
        return -1;
    }
};

/******************位运算***************/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int temp = 0;
            for (auto x : nums) {
                temp += ((x >> i) & 1);
            }
            if (temp % 3) ans |= (1 << i);
        }
        return ans;
    }
};