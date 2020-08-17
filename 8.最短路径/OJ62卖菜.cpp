/*************************************************************************
	> File Name: OJ62卖菜.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 17 Aug 2020 10:36:15 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_N 1000

struct Edge {
	int to, next, c;
} g[MAX_N * 3 + 5];
int head[MAX_N + 5], cnt = 0;
int dis[MAX_N + 5], vis[MAX_N + 5];
inline void add(int a, int b, int c) {
	g[++cnt] = {b, head[a], c};
	head[a] = cnt;
} 
int arr[MAX_N + 5];

void spfa(int s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(dis, 0, sizeof(vis));
	queue<int> q;
	dis[s] = 0, vis[s] = 1, q.push(s);
	while (!q.empty()) {
		int ind = q.front();
		q.pop(); vis[ind] = 0;
		for (int i = head[ind]; i; i = g[i].next) {
			int to = g[i].to, c = g[i].c;
			if (dis[ind] + c < dis[to]) {
				dis[to] = dis[ind] + c;
				vis[to] || (q.push(to), vis[to] = 1);
			}
		}
	}
	return ;
}

int main() {
	int n;
	cin >> n; 
	for (int i = 1; i <= n; i++) cin >> arr[i];
	//反向建图
    for (int i = 1; i <= n; i++) {
		int cnt = 1, sum = arr[i];
		if (i > 1) sum += arr[i - 1], cnt += 1;
		if (i < n) sum += arr[i + 1], cnt += 1;
		int ind1 = max(0, i - 2), ind2 = min(n, i + 1);
		add(ind1, ind2, -cnt * arr[i]);
		add(ind2, ind1, cnt * arr[i] + cnt - 1);
		add(i - 1, i, -1);
	}
	spfa(0);
	for (int i = 1; i <= n; i++) {
		i == 1 || cout << " ";
		cout << dis[i - 1] - dis[i];
	}
	cout << endl;
	return 0;
} 
