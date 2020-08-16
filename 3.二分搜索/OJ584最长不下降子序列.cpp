/*************************************************************************
	> File Name: OJ584最长不下降子序列.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 16 Aug 2020 08:39:32 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, num[100005], ans[100005], now;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	ans[0] = num[0];
	now++;
	for (int i = 1; i < n; i++) {
		if (num[i] >= ans[now - 1]) {
			ans[now] = num[i];
			now++;
		} else {
			int l = 0, r = now - 1;
			while (l != r) {
				int mid = (l + r) >> 1;
				if (ans[mid] <= num[i]) {
					l = mid + 1;
				} else {
					r = mid;
				}
			}
			ans[l] = num[i];
		}
	}
	cout << now << endl;
	return 0;
}
