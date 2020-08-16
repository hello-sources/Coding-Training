/*************************************************************************
	> File Name: OJ594能量区间.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 16 Aug 2020 09:27:39 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio> 
#include <algorithm>
using namespace std;

struct fu {
	int l, r;
};

int n, m;
fu fq[100005];

bool cmp(fu a, fu b) {
	return a.l < b.l;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &fq[i].l, &fq[i].r);
	} 
	fq[m].l = fq[m].r = 99999999;
	sort(fq, fq + m, cmp);
	int x = 0, ans = 0, mmin = fq[0].r, last = 0;
	//x有可能会产生影响的第一个负能量区间
	//mmin有可能会产生影响的第一个负能量区间的终点 
	//last有可能会产生影响的第一个负能量区间的起点 
	for (int i = 1; i <= n; i++) { //从1开始遍历 
		//如果负能量区间小于枚举的起点坐标，直接去掉这个方案 
		while (x <= m && fq[x].l < i) {
			x++;
		} 
		if (i == 1 || last < x) {
			mmin = fq[x].r;
			last = x;
			for (int j = x + 1; j <= m; j++) {
				if (mmin > fq[j].r) {
					mmin = fq[j].r;
					last = j;
				}
			}
		}
		ans += min(mmin, n + 1) - i; //枚举的终点减去起点 
	}
	printf("%d\n", ans); 
	return 0;
}
