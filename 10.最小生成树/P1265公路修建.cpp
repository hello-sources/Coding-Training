/*************************************************************************
	> File Name: P1265公路修建.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 13 Aug 2020 08:03:12 AM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct node {
    int now;
    double val;
    bool operator< (const node & b) const {
        return this->val > b.val;
    }
};

int n, xy[5005][2], vis[5005];
double dis[5005];

double D(int a, int b) {
    long long x = xy[a][0] - xy[b][0], y = xy[a][1] - xy[b][1];
    return sqrt(x * x + y * y);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dis[i] = 9999999999;
    }
    for (int i = 1; i <= n; i++) {
        cin >> xy[i][0] >> xy[i][1];
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    dis[1] = 0;
    double ans = 0;
    int already = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (vis[temp.now] == 1) {
            continue;
        }
        vis[temp.now] = 1;
        ans += temp.val;
        already++;
        if (already == n) {
            break;
        }
        for (int i = 1; i <= n; i++) {
            if (i == temp.now) {
                continue;
            }
            double t = D(temp.now, i);
            if (t < dis[i]) {
                dis[i] = t;
                que.push((node){i, t});
            }
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
