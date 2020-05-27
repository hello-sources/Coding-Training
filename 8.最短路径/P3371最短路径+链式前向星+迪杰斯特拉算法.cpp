/*************************************************************************
    > File Name: P3371最短路径+链式前向星+迪杰斯特拉算法.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 27 May 2020 10:54:31 PM CST
 ************************************************************************/


#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node {
    int e, dis, next;
};

struct point {
    int now, dist;
    bool operator< (const point &b) const {
        return this->dist > b.dist;
    }
};

int n, m, s, cnt, ans[10005], head[10005];
node edge[500005];
char mark[10005][10005];

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (!mark[a][b]) {
            mark[a][b] = 1;
            edge[cnt].e = b;
            edge[cnt].dis = c;
            edge[cnt].next = head[a];
            head[a] = cnt;
            cnt++;
        } else {
            int ind = head[a];
            while (edge[ind].e != b) {
                ind = edge[ind].next;
            }
            edge[ind].dis = min(edge[ind].dis, c);
        }
    }
    priority_queue<point> que;
    que.push({s, 0});
    while (!que.empty()) {
        point t = que.top();
        que.pop();
        if (ans[t.now] != 0x3F3F3F3F) continue;
        ans[t.now] = t.dist;
        for (int i = head[t.now]; i != -1; i = edge[i].next) {
            if (ans[edge[i].e] == 0x3F3F3F3F) {
                que.push({edge[i].e, t.dist + edge[i].dis});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        if (ans[i] == 0x3F3F3F3F) {
            cout << 0x7FFFFFFF;
        } else {
            cout << ans[i];
        }
    }
    return 0;
}
