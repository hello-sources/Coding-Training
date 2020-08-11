/*************************************************************************
	> File Name: P2820局域网.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 11 Aug 2020 08:51:01 AM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct edge {
    int to, val, next;
};

struct node {
    int now, val;
    bool operator< (const node & b) const {
        return this->val > b.val;
    }
};

edge edg[400005];
int n, m, edg_cnt, head[5005], ans, already, visit[5005], dis[5005], arr[105][105], all;

void add_edg(int a, int b, int c) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(dis, 0x3F, sizeof(dis));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0) {
            continue;
        }
        add_edg(a, b, c);
        add_edg(b, a, c);
        all += c;
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
        ans += temp.val;
        already++;
        if (already == n) {
            break;
        }
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            if (visit[edg[i].to] == 0 && dis[edg[i].to] > edg[i].val) {
                dis[edg[i].to] = edg[i].val;
                que.push((node){edg[i].to, edg[i].val});
            }
        }
    }
    cout << all - ans << endl;
    return 0;
}
