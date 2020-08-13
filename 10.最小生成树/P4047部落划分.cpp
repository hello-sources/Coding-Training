/*************************************************************************
	> File Name: P4047部落划分.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 14 Aug 2020 07:23:41 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm> 
#include <cmath>
#include <cstdio>
using namespace std;

struct edge {
	int from, to;
	double val;
};

bool cmp(edge a, edge b) {
	return a.val < b.val;
}

edge edg[500005];
int n, k, edg_cnt, xy[1005][2], my_union[1005], already = 1;

int find_fa(int x) {
	if (my_union[x] != x) {
		return my_union[x] = find_fa(my_union[x]);
	}
	return x;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> xy[i][0] >> xy[i][1];
		my_union[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int x = xy[i][0] - xy[j][0], y = xy[i][1] - xy[j][1];
			edg[edg_cnt].from = i;
			edg[edg_cnt].to = j;
			edg[edg_cnt].val = sqrt(x * x + y * y);
			edg_cnt++;
		}
	}
	sort(edg, edg + edg_cnt, cmp);
	int f = 0;
	for (int i = 0; i < edg_cnt; i++) {
		int fa = find_fa(edg[i].from), fb = find_fa(edg[i].to);
		if (fa != fb) {
			if (f == 1) {
				printf("%.2f\n", edg[i].val);
				break;
			}
			my_union[fa] = fb;
			already++;
			if (already == n - k + 1) {
				f = 1;
			}
		}
	}
	return 0;
} 
