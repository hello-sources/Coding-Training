/*************************************************************************
	> File Name: OJ46切割回文串.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 17 Aug 2020 09:28:54 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_N 500000
char str[MAX_N + 5]; 
struct Edge {
	int to, next;
} g[MAX_N << 2];
int head[MAX_N + 5], cnt = 0;
int dis[MAX_N + 5], vis[MAX_N + 5];
queue<int> q;
inline void add(int a, int b) {
	g[++cnt] = {b, head[a]};
	head[a] = cnt;
}

void spfa(int s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for (int i = head[x]; i; i = g[i].next) {
			int to = g[i].to;
			if (dis[x] + 1 >= dis[to]) continue;
			dis[to] = dis[x] + 1;
			if (!vis[to]) q.push(to), vis[to] = 1;
		}
	}
	return ;
} 

void expend(char *str, int i, int j) {
	while (i >= 0 && str[i] == str[j]) {
		add(i, j + 1);
		i -= 1, j += 1;
	}
	return ;
}

int main() {
	cin >> str; 
	for (int i = 0; str[i]; i++) {
		expend(str, i, i);
		expend(str, i, i + 1);
	}
	spfa(0);
	cout << dis[strlen(str)] - 1<< endl;
	return 0;
} 
