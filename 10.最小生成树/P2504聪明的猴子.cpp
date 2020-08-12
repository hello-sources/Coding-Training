/*************************************************************************
	> File Name: P2504聪明的猴子.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 12 Aug 2020 08:16:52 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct edge {
    int from, to;
    double val;
};

bool cmp(edge a, edge b) {
    return a.val < b.val;
}

edge edg[1000005];
int n, m, my_union[5005], edg_cnt, already = 1, monkey[505], xy[1005][2];
double ans;

int find_root(int x) {
    if (my_union[x] != x) {
        return my_union[x] = find_root(my_union[x]);
    }
    return x;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> monkey[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> xy[i][0] >> xy[i][1];
        my_union[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            edg[edg_cnt].from = i;
            edg[edg_cnt].to = j;
            double x = xy[i][0] - xy[j][0], y = xy[i][1] - xy[j][1];
            edg[edg_cnt].val = sqrt(x * x + y * y);
            edg_cnt++;
        }
    }
    sort(edg, edg + edg_cnt, cmp);
    for (int i = 0; i < edg_cnt; i++) {
        int aroot = find_root(edg[i].from), broot = find_root(edg[i].to);
        if (aroot != broot) {
            already++;
            ans = max(ans, edg[i].val);
            my_union[aroot] = broot;
            if (already == m) {
                break;
            }
        }
    }
    int fin = 0;
    for (int i = 1; i <= n; i++) {
        if (monkey[i] >= ans) {
            fin++;
        }
    }
    cout << fin << endl;
    return 0;
}
