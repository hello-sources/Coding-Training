/*************************************************************************
	> File Name: P4667最短路径.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 10 Jun 2020 07:20:50 PM CST
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
	bool operator< (const node &b) const {
		return this->now > b.now;
	}
};

edge edg[1100005];
int n, m, edg_cnt, head[260005], ans[260005];

void add_edg(int a, int b, int v) {
	edg[edg_cnt].to = b;
	edg[edg_cnt].val = v;
	edg[edg_cnt].next = head[a];
	head[a] = edg_cnt;
	edg_cnt++;
}

int main() {
	memset(head, -1, sizeof(head));
	memset(ans, 0x3F, sizeof(ans));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//i * (m + 1) + j           i * (m + 1) + j + 1
			//i * (m + 1) + j + m + 1   i * (m + 1) + j + m + 2
			char t;
			cin >> t;
			int a, b, c, d;
			if (t == '/') {
				a = i * (m + 1) + j + m + 1;
				b = i * (m + 1) + j + 1;
				c = i * (m + 1) + j;
				d = i * (m + 1) + j + m + 2;
			} else {
				c = i * (m + 1) + j + m + 1;
				d = i * (m + 1) + j + 1;
				a = i * (m + 1) + j;
				b = i * (m + 1) + j + m + 2;
			}
			add_edg(a, b, 0);
			add_edg(b, a, 0);
			add_edg(c, d, 1);
			add_edg(d, c, 1);
		}
	} 
	priority_queue<node> que;
	que.push((node){0, 0});
	ans[0] = 0;
	while (!que.empty()) {
		node temp = que.top();
		que.pop();
		if (temp.val != ans[temp.now]) {
			continue;
		}
		for (int cnt = head[temp.now]; cnt != -1; cnt = edg[cnt].next) {
			if (ans[edg[cnt].to] > ans[temp.now] + edg[cnt].val) {
				ans[edg[cnt].to] = ans[temp.now] + edg[cnt].val;
				que.push((node){edg[cnt].to, ans[edg[cnt].to]});
			}
		}
	}
	int x = ans[(n + 1) * (m + 1) - 1];
	if (x == 0x3f3f3f3f) {
		cout << "NO SOLUTION" << endl;
	} else {
		cout << x << endl; 
	}
	return 0;
} 
