/*************************************************************************
	> File Name: OJ334Interval_GCD.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 19 Sep 2020 07:39:05 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 500000
struct Node {
	long long d;
} tree[MAX_N >> 2];
int root = 1;
long long c[MAX_N + 5];
inline int lowbit(int x) { return x & (-x); }
void add(int x, long long val, int n) {
	while (x <= n) c[x] += val, x += lowbit(x);
}

long long query(int x) {
	int sum = 0;
	while (x) sum += c[x], x -= lowbit(x);
	return sum;
}

long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

void UP(int ind) {
	tree[ind].d = gcd(tree[ind << 1].d, tree[ind << 1 | 1].d);
	return ;
}

void build(int ind, int l, int r) {
	if (l == r) {
		tree[ind].d = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(ind << 1, l, mid);
	build(ind << 1 | 1, mid + 1, r);
	return ; 
}

void modify(int ind, int x, long long y, int l, int r) {
	if (l == r) {
		if (x - l) return ;
		tree[ind].d += y;
		return ;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) modify(ind << 1, x, y, l, mid);
	else modify(ind << 1 | 1, x, y, mid + 1, r);
	UP(ind);
	return ;
}

long long query(int ind, int x, int y, int l, int r) {
	if (x > y) return 0;
	if (x <= l && r <= y) {
		return tree[ind].d;
	}
	long long ans = 0;
	int mid = (l + r) >> 1;
	if (x <= mid) ans = gcd(query(ind << 1, x, y, l, mid), ans);
	if (y > mid) ans = gcd(query(ind << 1 | 1, x, y, mid + 1, r), ans);
	return ans;
}

int main() {
	long long n, m, now, pre = 0;
	char str[10];
	cin >> n >> m; 
	build(root, 1, n);
	for (int i = 1; i <= n; i++) {
		cin >> now;
		modify(root, i, now - pre, 1, n);
		add(i, now - pre, n);
		pre = now;
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		switch (str[0]) {
			case 'Q': {
				int l, r;
				long long x;
				cin >> l >> r;
				x = query(l);
				cout << "x : " << x << endl;
				cout << abs(gcd(x, query(root, l + 1, r, 1, n))) << endl;
				break;
			}
			case 'C': {
				int l, r;
				long long d;
				cin >> l >> r >>d;
				modify(root, l, d, 1, n);
				modify(root, r + 1, -d, 1, n);
				add(l, d, n);
				add(r + 1, -d, n);
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << query(i) << " ";
		}
		cout << endl;
	}
	return 0;
} 
