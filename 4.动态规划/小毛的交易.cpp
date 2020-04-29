#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct node {
	double val, cost, num;
} s[1005];

bool cmp(node a, node b) {
	return a.num > b.num;	
}

double m, n, ans;

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].val >> s[i].cost;
		s[i].num = s[i].val / s[i].cost;
	}
	sort(s, s + (int)n, cmp);
	for (int i = 0; i < n; i++) {
		if (m <= s[i].cost) {
			ans += s[i].num * m;
			break;
		}
		ans += s[i].val;
		m -= s[i].cost;
	}
	printf("%.3f\n", ans);
	return 0;
}
