/*******************for循环超时******************/
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int size = rating.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                for (int k = j + 1; k < size; k++) {
                    if ((rating[i] < rating[j] && rating[j] < rating[k]) ||
                        (rating[i] > rating[j] && rating[j] > rating[k])) ans++;
                }
            }
        }
        return ans;
    }
};

/*******************树状数组**************/
#define MAX_N 1005

class TreeArray {
public :
    int lowbit(int x) {
        return x & (-x);
    }

    TreeArray(int len) {
        n = len;
        memset(tree, 0, 4 * n + 1);
    }

    void update(int ind) {
        int i = ind + 1;
        while (i <= n) {
            tree[i]++;
            i += lowbit(i);
        }
        return ;
    }   

    int query(int p) {
        int res = 0;
        while (p > 0) {
            res += tree[p];
            p -= lowbit(p);
        }
        return res;
    }

private :
    int n;
    int tree[MAX_N];
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        TreeArray *u = new TreeArray(n + 1);
        vector<int> vec(n, 0);
        for (int i = 1; i < n; i++) vec[i] = i;
        sort(vec.begin(), vec.end(), [&](int &a, int &b){
            return rating[a] < rating[b];
        });
        for (int i = 0; i < n; i++) u_map[rating[vec[i]]] = i + 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int ind = u_map[rating[i]];
            int a = u->query(ind);
            int b = i - a;
            int c = ind - 1 - a;
            int d = n - 1 - a - b - c;
            ans += a * d + b * c;
            u->update(ind);
        }
        return ans;
    }

private :
    unordered_map<int, int> u_map;
};