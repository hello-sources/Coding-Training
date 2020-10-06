/*************************************************************************
	> File Name: OJ361没有上司的舞会.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 07 Oct 2020 07:44:29 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 6000
struct Edge {
	int to, next;
} g[MAX_N + 5]; 
int head[MAX_N + 5], indeg[MAX_N + 5], cnt = 0;
inline void add(int a, int b) {
	indeg[b] += 1;
	g[++cnt] = {b, head[a]};
	head[a] = cnt;
}
int h[MAX_N + 5], dp[MAX_N + 5][2];

void dfs(int ind) {
	dp[ind][0] = 0;
	dp[ind][1] = h[ind];
	for (int i = head[ind]; i; i = g[i].next) {
		int to = g[i].to;
		dfs(to);
		dp[ind][0] += max(dp[to][0], dp[to][1]);
		dp[ind][1] += dp[to][0];
	}
	return ;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> b >> a;
		if (!a && !b) break;
		add(a, b);
	}
	int root = 0;
	for (int i = 1; i <= n && !root; i++) {
		if (indeg[i] == 0) root = i;
	}
	dfs(root);
	cout << max(dp[root][0], dp[root][1]) << endl;
	return 0;
} 
