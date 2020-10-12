/*************************************************************************
	> File Name: OJ421直径.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 13 Oct 2020 07:26:12 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 200000
struct Edge {
    int to, next;
    long long c;
} g[MAX_N << 1];
int head[MAX_N + 5], cnt = 0;
long long dis[MAX_N + 5], vis[MAX_N + 5];
long long f[MAX_N + 5];
int pre[MAX_N + 5], nxt[MAX_N + 5];
inline void add(int a, int b, long long c) {
    g[++cnt] = {b, head[a], c};
    head[a] = cnt;
}

void dfs(int ind, int &x) {
    vis[ind] += 1;
    for (int i = head[ind]; i; i = g[i].next) {
        int to = g[i].to;
        long long c = g[i].c;
        if (vis[to]) continue;
        dis[to] = dis[ind] + c;
        pre[to] = ind;
        dfs(to, x);
    }
    if (dis[ind] > dis[x]) x = ind;
    vis[ind] -= 1;
    return ;
}

int main() {
    int n, s = 1, t = 1;
    cin >> n;
    for (int i = 1; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dis[1] = 0, pre[1] = 0;
    dfs(1, s);
    dis[s] = 0, pre[s] = 0;
    dfs(s, t);
    cout << dis[t] << endl;
    int p = t;
    while (p) {
        nxt[pre[p]] = p;
        f[p] = dis[p];
        vis[p] = 1;
        p = pre[p];
    }
    for (int i = s; i; i = nxt[i]) {
        int x = i;
        dis[i] = 0;
        dfs(i, x);
        dis[i] = dis[x];
    }
    int ans = 0, i = t;
    while (i && f[i] != dis[i]) i = pre[i];
    while (i && f[t] - f[i] != dis[i]) i = nxt[i], ans += 1;
    cout << ans << endl;
    return 0;
}
