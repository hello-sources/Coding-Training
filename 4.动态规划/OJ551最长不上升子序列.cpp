/*************************************************************************
	> File Name: OJ551最长不上升子序列.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 06 Aug 2020 06:42:55 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, num[2005], ans[2005];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		ans[i] = 1;
	}
	int ans1 = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <i; j++) {
			if (num[i] <= num[j]) {
				ans[i] = max(ans[i], ans[j] + 1);
			}
		}
		ans1 = max(ans1, ans[i]);
	}
	cout << ans1 << endl;
	return 0;
}
