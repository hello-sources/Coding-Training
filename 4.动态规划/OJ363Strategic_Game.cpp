/*************************************************************************
	> File Name: OJ363Strategic_Game.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 09 Oct 2020 07:27:14 AM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 1500
struct Edge {
	int to, next;
} g[(MAX_N << 1) + 5];
int head[MAX_N + 5], cnt = 0;
inline void add(int a, int b) {
	g[++cnt] = {b, head[a]};
	head[a] = cnt;
}
int dp[MAX_N + 5][2];

void dfs(int fa, int x) {
	dp[x][0] = 0;
	dp[x][1] = 1;
	int flag = 1, cnt = 0;
	for (int i = head[x]; i; i = g[i].next) {
		int to = g[i].to;
		if (to == fa) continue;
		cnt += 1;
		dfs(x, to);
		dp[x][0] += min(dp[to][0], dp[to][1]);
		dp[x][1] += min(dp[to][0], dp[to][1]);
		if (dp[to][1] <= dp[to][0]) flag = 0;
	}
	dp[x][0] += (flag && cnt);
	return ;
}

void solve(int n) {
	memset(head, 0, sizeof(head));
	cnt = 0;
	int a, m, b;
	for (int i = 0; i < n; i++) {
		scanf("%d:(%d)", &a, &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &b);
			add(a, b);
			add(b, a);
		}
	}
	dfs(-1, 0);
	cout << min(dp[0][0], dp[0][1]) << endl;
	return ;
}

int main() {
	int n;
	while (cin >> n) {
		solve(n);
	} 
	return 0;
} 
