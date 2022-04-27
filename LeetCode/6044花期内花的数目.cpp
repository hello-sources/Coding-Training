class Solution {
public:
    int size = pow(10, 9) + 1;
    inline int lowbit(int x) {
        return x & (-x);
    }

    void update(int x, int val) {
        while (x <= size) {
            C[x] += val;
            x += lowbit(x);
        }
        return ;
    }    

    int query(int x) {
        int sum = 0;
        while (x) {
            sum += C[x];
            x -= lowbit(x);
        }
        return sum;
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> ans(persons.size(), 0);
        for (auto flower : flowers) {
            int l = flower[0], r = flower[1];
            update(l, 1);
            update(r + 1, -1);
        }
        for (int i = 0; i < persons.size(); i++) {
            ans[i] = query(persons[i]);
        }
        return ans;
    }

private :
    unordered_map<int, int> C;
};