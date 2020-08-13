/*************************************************************************
	> File Name: P2212浇水.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 13 Aug 2020 08:28:34 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct edge {
    int from, to, val;
};

bool cmp(edge a, edge b) {
    return a.val < b.val;
}

edge edg[2000005];
int n, c, edg_cnt, xy[2005][2], ans, already = 1, my_union[2005];

int find_fa(int x) {
    if (my_union[x] != x) {
        return my_union[x] = find_fa(my_union[x]);
    }
    return x;
}

int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        my_union[i] = i;
        cin >> xy[i][0] >> xy[i][1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = xy[i][0] - xy[j][0], y = xy[i][1] - xy[j][1];
            edg[edg_cnt].from = i;
            edg[edg_cnt].to = j;
            edg[edg_cnt].val = x * x + y * y;
            edg_cnt++;
        }
    }
    sort(edg, edg + edg_cnt, cmp);
    for (int i = 0; i < edg_cnt; i++) {
        if (edg[i].val < c) {
            continue;
        }
        int fa = find_fa(edg[i].from), fb = find_fa(edg[i].to);
        if (fa != fb) {
            my_union[fa] = fb;
            ans += edg[i].val;
            already++;
            if (already == n) {
                break;
            }
        }
    }
    if (already == n) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
