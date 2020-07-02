/*************************************************************************
	> File Name: P2829大逃离.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 02 Jul 2020 03:31:59 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct edge {
    int from, to, val, next;
};

edge edg[200005];
int n, m, k, edg_cnt, head[5005], ans[5005], ans2[5005], mark[5005], connect[5005];
char edg_mark[5005][5005];

void add_edge(int a, int b, int c) {
    edg[edg_cnt].from = a;
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt;
    edg_cnt++;
}

int main() {
    memset(ans, 0x3F, sizeof(ans));
    memset(ans2, 0x3F, sizeof(ans2));
    memset(head, -1, sizeof(head));
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (edg_mark[a][b] == 0) {
            connect[a]++;
            connect[b]++;
        }
        edg_mark[a][b] = 1;
        edg_mark[b][a] = 1;
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    queue<int> que;
    que.push(1);
    ans[1] = 0;
    mark[1] = 1;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        mark[t] = 0;
        for (int cnt = head[t]; cnt != -1; cnt = edg[cnt].next) {
            if (ans[edg[cnt].to] > ans[t] + edg[cnt].val && (edg[cnt].to == n || connect[edg[cnt].to] >= k)) {
                ans[edg[cnt].to] = ans[t] + edg[cnt].val;
                if (mark[edg[cnt].to] == 0) {
                    mark[edg[cnt].to] = 1;
                    que.push(edg[cnt].to);
                }
            }
        }
    }
    que.push(n);
    ans2[n] = 0;
    mark[n] = 1;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        mark[t] = 0;
        for (int cnt = head[t]; cnt != -1; cnt = edg[cnt].next) {
            if (ans2[edg[cnt].to] > ans2[t] + edg[cnt].val && (edg[cnt].to == 1 || connect[edg[cnt].to] >= k)) {
                ans2[edg[cnt].to] = ans2[t] + edg[cnt].val;
                if (mark[edg[cnt].to] == 0) {
                    mark[edg[cnt].to] = 1;
                    que.push(edg[cnt].to);
                }
            }
        }
    }
    int fin = 999999999;
    for (int i = 0; i < edg_cnt; i++) {
        int t = ans[edg[i].from] + ans2[edg[i].to] + edg[i].val;
        int a = edg[i].from, b = edg[i].to;
        if (fin > t && t != ans[n] && ((connect[a] >= k && connect[b] >= k) || a == 1 || b == 1 || a == n || b == n)) {
            fin = t;
        }
    }
    if (fin != 999999999) {
        cout << fin << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
