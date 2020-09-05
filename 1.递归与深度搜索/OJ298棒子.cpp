/*************************************************************************
	> File Name: OJ298棒子.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 05 Sep 2020 08:50:46 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 70
int a[MAX_N + 5];
int v[MAX_N + 5]; 
int n, len;

bool cmp(int a, int b) {
	return a > b;
}

bool dfs(int res, int ind, int c) {
	if (c == 0) return true;
	if (res == 0) {
		res = len;
		ind = 0;
	}
	for (int i = ind, j = 0; i < n; i++) {
		if (v[i] || a[i] > res || j == a[i]) continue;
		j = a[i];
		v[i] = 1;
		if (dfs(res - a[i], i + 1, c - 1)) return true;
		v[i] = 0;
		if (res == len || res == a[i]) return false;
	}
	return false;
}

void solve() {
	int sum = 0,val = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		val = max(val, a[i]);
	}
	sort(a, a + n, cmp);
	for (int l = val; l <= sum; l++) {
		if (sum % l) continue;
		len = l;
		memset(v, 0, sizeof(v));
		if (!dfs(l, 0, n)) continue;
		cout << l << endl;
		break;
	}
	return ;
}

int main() {
	while (cin >> n) {
		if (n == 0) break;
		solve();
	}
	return 0;
} 
