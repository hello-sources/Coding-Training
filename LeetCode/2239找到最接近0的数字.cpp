class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int num = INT_MAX, len = INT_MAX;
        for (auto &x : nums) {
            int temp = abs(x - 0);
            if (temp < len) {
                len = temp;
                num = x;
            } else if (temp == len) {
                if (x > num)num = x;
            }
        }
        return num;
    }
};