class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> elems;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) elems.push_back(i);
        }
        return k > elems.size() ? -1 : elems[k - 1];
    }
};