/*************************************************************************
	> File Name: OJ579相似的数集.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 15 Aug 2020 08:14:10 AM CST
 ************************************************************************/

#include <iostream>
#include <set>
#include <cstdio> 
using namespace std;

set<int> se[51];
char check[51][1000001];
int n, k;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int m;
		scanf("%d", &m);
		while (m--) {
			int t;
			scanf("%d", &t);
			check[i][t] = 1;
			se[i].insert(t);
		}
	}
	scanf("%d", &k);
	while (k--) {
		int a, b, cnt = 0;
		scanf("%d%d", &a, &b);
		for (set<int>::iterator it = se[a].begin(); it != se[a].end(); it++) {
			if (check[b][*it] == 1) cnt++;
		}
		printf("%.1f%%\n", 100.0 * cnt / (se[a].size() + se[b].size() - cnt));
	}
	
	return 0;
}
