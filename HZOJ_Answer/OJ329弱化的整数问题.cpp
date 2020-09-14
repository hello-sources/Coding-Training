/*************************************************************************
	> File Name: OJ329弱化的整数问题.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 15 Sep 2020 07:20:39 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000
int c[MAX_N + 5]; 
inline int lowbit(int x) { return x & (-x); }
void add(int x, int val, int n) {
	while (x <= n) c[x] += val, x += lowbit(x);
}

int query(int x) {
	int sum = 0;
	while (x) sum += c[x], x -= lowbit(x);
	return sum;
}

int main() {
	int n, pre = 0, now, m;
	char str[10];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> now;
		add(i, now - pre, n);
		pre = now;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> str;
		switch (str[0]) {
			case 'C': {
				int l, r, d;
				cin >> l >> r >> d;
				add(l, d, n);
				add(r + 1, -d, n);
				break;
			}
			case 'Q': {
				int x;
				cin >> x;
				cout << query(x) << endl;
				break;
			}
		}
	}
	return 0;
}
