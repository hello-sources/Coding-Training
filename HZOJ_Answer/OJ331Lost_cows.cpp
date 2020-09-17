/*************************************************************************
	> File Name: OJ331Lost_cows.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 17 Sep 2020 09:00:32 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 80000
int c[MAX_N + 5];
int ind[MAX_N + 5], ans[MAX_N + 5];
inline int lowbit(int x) { return x & (-x); }
void add(int x, int val, int n) {
	while (x <= n) c[x] += val, x += lowbit(x);
}

int query(int x) {
	int sum = 0;
	while (x) sum += c[x], x -= lowbit(x);
	return sum;
}

int binary_search(int x, int n) {
	int head = 1, tail = n, mid;
	while (head < tail) {
		mid = (head + tail) >> 1;
		if (query(mid) < x) head = mid + 1;
		else tail = mid;
	}
	return head;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) add(i, 1, n);
	for (int i = 2; i <= n; i++) cin >> ind[i];
	for (int i = n; i >= 1; --i) {
		int x = binary_search(ind[i] + 1, n);
		ans[i] = x;
		add(x, -1, n);
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
