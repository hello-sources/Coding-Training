class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_map<string, int> u_map;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;
            string temp;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] % p == 0) cnt++;
                if (cnt > k) break;
                temp += nums[j] + '0';
                u_map[temp] = 1;
            }
        }
        return u_map.size();
    }
};