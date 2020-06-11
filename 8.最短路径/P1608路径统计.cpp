/*************************************************************************
	> File Name: P1608路径统计.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 11 Jun 2020 12:08:19 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
    int to, val, next;
};

struct node {
    int now, val;
    bool operator< (const node &b) const {
        return this->val > b.val;
    }
};

edge edg[4000005];
char mark[2001][2001];
int n, m, edg_cnt, head[2004], ans[2005], ans_cnt[2005];

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3F, sizeof(ans));
    memset(ans_cnt, 0, sizeof(ans_cnt));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (mark[a][b] == 0) {
            mark[a][b] = 1;
            edg[edg_cnt].to = b;
            edg[edg_cnt].val = c;
            edg[edg_cnt].next = head[a];
            head[a] = edg_cnt;
            edg_cnt++;
        } else {
            int cnt = head[a];
            while (edg[cnt].to != b) {
                cnt = edg[cnt].next;
            }
            edg[cnt].val = min(edg[cnt].val, c);
        }
    }
    priority_queue<node> que;
    que.push({1, 0});
    ans[1] = 0;
    ans_cnt[1] = 1;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.val > ans[temp.now]) {
            continue;
        }
        for (int cnt = head[temp.now]; cnt != -1; cnt = edg[cnt].next) {
            if (ans[edg[cnt].to] > temp.val + edg[cnt].val) {
                ans[edg[cnt].to] = temp.val + edg[cnt].val;
                ans_cnt[edg[cnt].to] = ans_cnt[temp.now];
                que.push({edg[cnt].to, ans[edg[cnt].to]});
            } else if (ans[edg[cnt].to] == temp.val + edg[cnt].val) {
                ans_cnt[edg[cnt].to] += ans_cnt[temp.now];
            }
        }
    }
    if (ans[n] != 0x3F3F3F3F) {
        cout << ans[n] << " " << ans_cnt[n] << endl;
    } else {
        cout << "No answer" << endl;
    }
    return 0;
}
