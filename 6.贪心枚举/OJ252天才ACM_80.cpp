/*************************************************************************
	> File Name: OJ252天才ACM_80.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 20 Aug 2020 09:10:00 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 500000 
int arr[MAX_N + 5];

inline int S(int x) { return x * x; }

bool is_val(int *arr, int l, int r, int k, int m) {
	int spd = 0;
	for (int i = r; i > l; --i) {
		if (arr[i] >= arr[i - 1]) break;
		swap(arr[i], arr[i - 1]);
	}
	for (int i = l, j = r; i < j && m; i++, j--, m--) {
		spd += S(arr[i] - arr[j]);
	}
	return spd <= k;
}

void solve() {
	int n, m, k, pre = 0, cnt = 1;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		int temp = arr[i];
		if (is_val(arr, pre, i, k, m)) continue;
		arr[i] = temp;
		pre = i;
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
