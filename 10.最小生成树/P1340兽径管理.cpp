/*************************************************************************
	> File Name: P1340兽径管理.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 13 Aug 2020 08:26:14 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm> 
using namespace std;

struct edge {
	int from, to, val, mtime;
};

bool cmp (edge a, edge b) {
	return a.val < b.val;
}
edge edg[6005];
int n, m, my_union[205];

int find_root(int x) {
	if (my_union[x] != x) {
		return my_union[x] = find_root(my_union[x]);
	}
	return x;
}

void init_union() {
	for (int i = 1; i <= n; i++) {
		my_union[i] = i;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> edg[i].from >> edg[i].to >> edg[i].val;
		edg[i].mtime = i;
	}
	sort(edg, edg + m, cmp);
	for (int i = 0; i < m; i++) {
		int ans = 0, already = 1;
		init_union();
		for (int j = 0; j < m; j++) {
			if (edg[j].mtime <= i) {
				int fa = find_root(edg[j].from), fb = find_root(edg[j].to);
				if (fa != fb) {
					my_union[fa] = fb;
					ans += edg[j].val;
					already++;
					if (already == n) {
						break;
					}
				}
			}
		}
		if (already == n) {
			cout << ans << endl;
		} else {
			cout << -1 << endl;
		}
	} 
	
	return 0;
}
