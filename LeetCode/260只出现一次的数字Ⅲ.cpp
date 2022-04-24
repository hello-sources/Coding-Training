class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> u_map;
        for (auto &x : nums) u_map[x]++;
        for (auto iter: u_map) {
            if (iter.second == 1) ans.emplace_back(iter.first);
        }
        return ans;
    }
};

/*******************位运算**************/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_num = 0;
        for (auto &x : nums) xor_num ^= x;
        int cmp_xor = (xor_num  == INT_MIN ? xor_num : (xor_num & (-xor_num)));
        int num1 = 0, num2 = 0;
        for (auto &x : nums) {
            if (x & cmp_xor) num1 ^= x;
            else num2 ^= x;
        }
        return {num1, num2};
    }
};