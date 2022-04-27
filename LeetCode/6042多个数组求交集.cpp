class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> vec(1005, 0);
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                vec[nums[i][j]]++;
            }
        }
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == nums.size()) ans.push_back(i);
        } 
        sort(ans.begin(), ans.end());
        return ans;
    }
};