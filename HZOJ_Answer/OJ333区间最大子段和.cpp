/*************************************************************************
	> File Name: OJ333区间最大子段和.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 18 Sep 2020 07:27:18 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 500000 
#define SUM(ind) tree[ind].sum
#define INMAX(ind) tree[ind].inmax
#define LMAX(ind) tree[ind].lmax
#define RMAX(ind) tree[ind].rmax
#define lc(ind) (ind << 1)
#define rc(ind) (ind << 1 | 1)

struct Node {
	int sum, inmax, lmax, rmax;
} tree[MAX_N << 2];
int root = 1;
int arr[MAX_N + 5];

void _UP(Node &a, Node &b) {
	a.inmax = max(a.inmax, max(b.inmax, a.rmax + b.lmax));
	a.lmax = max(a.lmax, a.sum + b.lmax);
	a.rmax = max(b.rmax, b.sum + a.rmax); 
	a.sum += b.sum;
	return ;
}

void UP(int ind) {
	tree[ind] = tree[lc(ind)];
	_UP(tree[ind], tree[rc(ind)]);
	return ;
}

void modify(int ind, int x, int y, int l, int r) {
	if (l == r) {
		SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = y;
		return ;
	} 
	int mid = (l + r) >> 1;
	if (x <= mid) modify(lc(ind), x, y, l, mid);
	else modify(rc(ind), x, y, mid + 1, r);
	UP(ind);
	return ;
}

void build(int ind, int l, int r) {
	if (l == r) {
		SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = arr[l];
		return ;
	} 
	int mid = (l + r) >> 1;
	build(lc(ind), l, mid);
	build(rc(ind), mid + 1, r);
	UP(ind);
	return ;
}

void query(int ind, int x, int y, int l, int r, Node &ret) {
	if (x <= l && r <= y) {
		if (l == x) ret = tree[ind];
		else _UP(ret, tree[ind]);
		return ;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) query(lc(ind), x, y, l, mid, ret);
	if (y > mid) query(rc(ind), x, y, mid + 1, r, ret);
	return ;  
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	build(root, 1, n);
	for (int i = 0; i < m; i++) {
		int k, x, y;
		cin >> k >> x >> y;
		switch (k) {
			case 2: modify(root, x, y, 1, n); break;
			case 1: {
				if (x > y) swap(x, y);
				Node ret;
				query(root, x, y, 1, n, ret);
				cout << ret.inmax << endl;
				break;
			}
		}
	}
	return 0;
}
