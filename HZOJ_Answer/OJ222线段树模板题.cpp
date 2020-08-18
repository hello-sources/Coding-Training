/*************************************************************************
	> File Name: OJ222线段树模板题.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 18 Aug 2020 08:04:36 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 10000
#define NUM(ind) tree[ind].num
#define lc(ind) (ind << 1)
#define rc(ind) (ind << 1 | 1)
struct Node {
	int num;	
} tree[(MAX_N << 2) + 5]; 
int root = 1;
int arr[MAX_N + 5];

void UP(int ind) {
	NUM(ind) = max(NUM(lc(ind)), NUM(rc(ind)));
}

void build(int ind, int l, int r) {
	if (l == r) {
		NUM(ind) = arr[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(lc(ind), l, mid);
	build(rc(ind), mid + 1, r);
	UP(ind);
	return ;
}

void modify(int ind, int x, int y, int l, int r) {
	if (l == r) {
		NUM(ind) = y;
		return ;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) modify(lc(ind), x, y, l, mid);
	else modify(rc(ind), x, y, mid + 1, r);
	UP(ind);
	return ;
}

int query(int ind, int x, int y, int l, int r) {
	if (x <= l && r <= y) {
		return NUM(ind);
	}
	int ans = 0x80000000;
	int mid = (l + r) >> 1;
	if (x <= mid) ans = query(lc(ind), x, y, l, mid);
	if (y > mid) ans = max(ans, query(rc(ind), x, y, mid + 1, r));
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	build(root, 1, n); 
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		switch (a) {
			case 1: modify(root, b, c, 1, n); break;
			case 2: cout << query(root, b, c, 1, n) << endl; break;
		}
	}
	return 0;
}
