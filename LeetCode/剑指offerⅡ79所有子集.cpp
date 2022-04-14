class Solution {
private:
    vector<int> temp;
    vector<vector<int>> ans;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        for (int i = 0; i < (1 << nums.size()); i++) {
            temp.clear();
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};