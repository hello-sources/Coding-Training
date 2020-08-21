/*************************************************************************
	> File Name: OJ252天才ACM_二分.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 21 Aug 2020 08:11:20 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 500000 
long long arr[MAX_N + 5];
long long temp[MAX_N + 5];

inline long long S(int x) { return x * x; }

long long spd_value(long long *arr, int l, int r, int m) {
	int spd = 0;
	memcpy(temp, arr + l, sizeof(long long) * (r - l + 1));
	sort(temp, temp + (r - l + 1));
	for (int i = 0, j = r - l;i < j && m; i++, j--, m--) {
		spd += S(temp[i] - temp[j]);
	}
	return spd;
}

int get_next(long long *arr, int l, int r, long long k, int m) {
	int head = 1, tail = r, mid;
	while (head < tail) {
		mid = (head + tail + 1) >> 1;
		if (spd_value(arr, l, mid, m) <= k) head = mid;
		else tail = mid - 1;
	}
	return head + 1;
}

void solve() {
	long long n, m, k, pre = 0, cnt = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	while (pre < n) {
		pre = get_next(arr, pre, n, k, m);
		cnt += 1;
	}
	cout << cnt << endl;
	return ;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
