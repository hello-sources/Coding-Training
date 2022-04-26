class Solution {
public:
    int getW(int x) {
        if (x == 1) return 0;
        if (x % 2) return getW(x * 3 + 1) + 1;
        else return getW(x / 2) + 1;
    }

    int getKth(int lo, int hi, int k) {
        vector<int> vec;
        for (int i = lo; i <= hi; i++) vec.push_back(i);
        sort(vec.begin(), vec.end(), [&](int a, int b){
            if (getW(a) != getW(b)) return getW(a) < getW(b);
            else return a < b;
        });
        return vec[k - 1];
    }
};