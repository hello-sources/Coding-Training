#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct node {
	double x, y;
};

int n;
node p[100005];

bool cmp(node a, node b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

double dis(int p1, int p2) {
	return sqrt((p[p1].x - p[p2].x) * (p[p1].x - p[p2].x) + (p[p1].y - p[p2].y) * (p[p1].y - p[p2].y));
}

double func(int l, int r) {
	if (l == r) {
		return 2100000000;
	}
	if (l + 1 == r) {
		return dis(l, r);
	}
	int mid = (l + r) >> 1;
	double d = min(func(1, mid), func(mid + 1, r));
	for (int i = mid; i >= 0 && p[mid].x - p[i].x < d; i--) {
		for (int j = mid + 1; j < r && p[j].x - p[mid].x < d; j++) {
			d = min(d, dis(i, j));
		}
	}
	return d;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}
	sort(p, p + n, cmp);
	double ans = func(0, n - 1);
	printf("%f\n", ans);
	return 0;
}
