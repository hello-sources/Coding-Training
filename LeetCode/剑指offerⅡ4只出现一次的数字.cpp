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