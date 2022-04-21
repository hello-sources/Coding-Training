class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ans;
        unordered_set<int> temp(nums1.begin(), nums1.end());
        for (auto &x : nums2) {
            if (temp.find(x) != temp.end()) ans.insert(x);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};