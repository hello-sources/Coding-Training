/*************************************************************************
	> File Name: OJ330加强的整数问题.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 16 Sep 2020 09:44:10 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000
long long c[2][MAX_N + 5];
inline int lowbit(int x) { return x & (-x); } 

void add(int k, int x, long long val, int n) {
	while (x <= n) c[k][x] += val, x += lowbit(x); 
}

long long query(int k, int x) {
	long long sum = 0;
	while (x) sum += c[k][x], x -= lowbit(x);
	return sum;
}

int main() {
	int n, m;
	long long pre = 0, now;
	char str[10];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> now;
		add(0, i, now - pre, n);
		add(1, i, i * (now - pre), n);
		pre = now;
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		switch (str[0]) {
			case 'C': {
				long long l, r, val;
				cin >> l >> r >> val;
				add(0, l, val, n);
				add(0, r + 1, -val, n);
				add(1, l, l * val, n);
				add(1, r + 1, - (i + 1) * val, n);
				break;
			}
			case 'Q': {
				int l, r;
				cin >> l >> r;
				l -= 1;
				long long val1 = (l + 1) * query(0, l) - query(1, l);
				long long val2 = (r + 1) * query(0, r) - query(1, r);
				cout << val2 - val1 << endl;
				break;
			} 
		}
	}
	
	return 0;
}
