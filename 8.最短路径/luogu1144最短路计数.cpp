/*************************************************************************
    > File Name: luogu1144最短路计数.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 03 Jun 2020 08:55:49 PM CST
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
int n, m, edg_cnt, head[1000005], ans[1000005], ans_cnt[100005];

int main() {
	memset(head, -1, sizeof(head));
	memset(ans, 0x3f, sizeof(ans));
	memset(ans_cnt, 0, sizeof(ans_cnt));
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edg[edg_cnt].to = b;
		edg[edg_cnt].val = 1;
		edg[edg_cnt].next = head[a];
		head[a] = edg_cnt;
		edg_cnt++;
		edg[edg_cnt].to = a;
		edg[edg_cnt].val = 1;
		edg[edg_cnt].next = head[b];
		head[b] = edg_cnt;
		edg_cnt++;
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
			} else if (ans[edg[cnt].to] == temp.val + edg[cnt].val){
				ans_cnt[edg[cnt].to] += ans_cnt[temp.now];
				ans_cnt[edg[cnt].to] %= 100003;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans_cnt[i] << endl;
	}
	
	return 0;
}
