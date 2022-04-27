class Solution {
public:
    int lowbit(int x) {
        return x & (-x);
    }

    void update(int x, int size) {
        while (x < size) {
            diff[x]++;
            x += lowbit(x);
        }
        return ;
    }

    int query(int x, int size) {
        int sum = 0;
        while (x) {
            sum += diff[x];
            x -= lowbit(x);
        }
        return sum;
    }
    
    void discretization(vector<int> &nums) {
        a.assign(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        return ;
    }

    int getId(int x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        discretization(nums);
        diff.resize(nums.size() + 5);
        int size = diff.size();
        for (int i = nums.size() - 1; i >= 0; i--) {
            int id = getId(nums[i]);
            ans.push_back(query(id - 1, size));
            update(id, size);
        } 
        reverse(ans.begin(), ans.end());
        return ans;
    }

private :
    vector<int> diff;
    vector<int> a;
};