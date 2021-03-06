/*************************************************************************
	> File Name: P1546最短网络.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 11 Aug 2020 08:39:50 AM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
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
int n, m, edg_cnt, head[5005], ans, already, visit[5005], dis[5005], arr[105][105];
//dis[]数组表示这个点到那条边的权值 

void add_edg(int a, int b, int c) {
	edg[edg_cnt].to = b;
	edg[edg_cnt].val = c;
	edg[edg_cnt].next = head[a];
	head[a] = edg_cnt++;
}

int main() {
	memset(head, -1, sizeof(head));
	memset(dis, 0x3F, sizeof(dis));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (i < j) {
				add_edg(i, j, arr[i][j]);
				add_edg(j, i, arr[i][j]);
			}
		}
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
	cout << ans << endl;
	return 0;
} 
