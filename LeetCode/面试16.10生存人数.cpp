class Solution {
public:
    int lowbit(int x) {
        return x & (-x);
    }

    void update(int x, int val, int size) {
        while (x <= size) {
            c[x] += val;
            x += lowbit(x);
        }
        return ;
    }

    int query(int x, int size) {
        int sum = 0;
        while (x) {
            sum += c[x];
            x -= lowbit(x);
        }
        return sum;
    }

    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int size = birth.size();
        int len = 105;
        c.resize(len);
        for (int i = 0; i < size; i++) {
            update(birth[i] - 1899, 1, len);
            update(death[i] + 1 - 1899, -1, len);
        }
        int year = 0, min_p = 0;
        for (int i = 1; i < len; i++) {
            int temp = query(i, len);
            if (temp > min_p) {
                min_p = temp;
                year = i + 1899;
            }
        }
        return year;
    }

private :
    vector<int> c;
};