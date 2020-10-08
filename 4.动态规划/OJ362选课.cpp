/*************************************************************************
	> File Name: OJ362选课.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 08 Oct 2020 08:57:39 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 300
#define INF 0x3f3f3f3f
struct Edge {
	int to, next;
} g[(MAX_N << 1) + 5];
int head[MAX_N + 5], cnt = 0;
inline void add(int a, int b) {
	g[++cnt] = {b, head[a]};
	head[a] = cnt;
}
int dp[MAX_N + 5][MAX_N + 5]; 
int val[MAX_N + 5], size[MAX_N + 5];
int tmp[MAX_N + 5];

void dfs(int fa, int x) {
	size[x] = 1;
	dp[x][0] = 0;
	dp[x][1] = val[x];
	for (int i = head[x]; i; i = g[i].next) {
		int to = g[i].to;
		if (to == fa) continue;
		dfs(x, to);
		size[x] += size[to];
		memcpy(tmp, dp[x], sizeof(tmp));
		for (int j = 1; j <= size[x]; j++) {
			for (int k = 0; k < j && k <= size[to]; k++) {
				dp[x][j] = max(dp[x][j], tmp[j - k] + dp[to][k]);
			}
		}
	}
	return ;
}

void init() {
	for (int i = 0; i <= MAX_N; i++) {
		for (int j = 0; j <= MAX_N; j++) {
			dp[i][j] = -INF;
		}
	}
	return ;
}

int main() {
	init();
	int n, m, a;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a >> val[i];
		add(a, i);
	}
	dfs(-1, 0);
	cout << dp[0][m + 1] << endl;
	return 0;
} 
