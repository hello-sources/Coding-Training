/*************************************************************************
	> File Name: P2504聪明的猴子_prim.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 12 Aug 2020 08:22:19 AM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

struct edge {
    int to, next;
    double val;
};

struct node {
    int now;
    double val;
    bool operator< (const node & b) const {
        return this->val > b.val;
    }
};

edge edg[1000005];
int n, m, edg_cnt, head[5005], already, visit[5005], monkey[500], xy[1005][2];
double ans, dis[5005];

void add_edg(int a, int b, double c) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> monkey[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        dis[i] = 999999999;
        cin >> xy[i][0] >> xy[i][1];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            double x = xy[i][0] - xy[j][0], y = xy[i][1] - xy[j][1];
            double t = sqrt(x * x + y * y);
            add_edg(i, j, t);
            add_edg(j, i, t);
        }
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (visit[temp.now] == 1) {
            continue;
        }
        visit[temp.now] = 1;
        ans = max(ans, temp.val);
        already++;
        if (already == m) {
            break;
        }
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            if (visit[edg[i].to] == 0 && dis[edg[i].to] > edg[i].val) {
                dis[edg[i].to] = edg[i].val;
                que.push((node){edg[i].to, edg[i].val});
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
