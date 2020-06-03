/*************************************************************************
    > File Name: P1629邮递员送信_SPFA.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 03 Jun 2020 11:12:28 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
    int to, val, next;
};

int n, m, head1[1005], head2[1005], ans1[1005], ans2[1005], que_mark[1005];
edge edg1[100005], edg2[100005];

int main() {
    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));
    memset(ans1, 0x3F, sizeof(ans1));
    memset(ans2, 0x3F, sizeof(ans2));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg1[i].to = b;
        edg1[i].val = c;
        edg1[i].next = head1[a];
        head1[a] = i;
        edg2[i].to = a;
        edg2[i].val = c;
        edg2[i].next = head2[b];
        head2[b] = i;
    }
    ans1[1] = 0;
    queue<int> que;
    que.push(1);
    que_mark[1] = 1;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        que_mark[t] = 0;
        for (int cnt = head1[t]; cnt != -1; cnt = edg1[cnt].next) {
            if (ans1[edg1[cnt].to] > ans1[t] + edg1[cnt].val) {
                ans1[edg1[cnt].to] = ans1[t] + edg1[cnt].val;
                if (que_mark[edg1[cnt].to] == 0) {
                    que_mark[edg1[cnt].to] = 1;
                    que.push(edg1[cnt].to);
                }
            }
        }
    }
    ans2[1] = 0;
    que.push(1);
    que_mark[1] = 1;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        que_mark[t] = 0;
        for (int cnt = head2[t]; cnt != -1; cnt = edg2[cnt].next) {
            if (ans2[edg2[cnt].to] > ans2[t] + edg2[cnt].val) {
                ans2[edg2[cnt].to] = ans2[t] + edg2[cnt].val;
                if (que_mark[edg2[cnt].to] == 0) {
                    que_mark[edg2[cnt].to] = 1;
                    que.push(edg2[cnt].to);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += ans1[i] + ans2[i];
    }
    cout << ans << endl;
    return 0;
}
