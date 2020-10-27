/*************************************************************************
	> File Name: OJ567钻石收集者.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 28 Oct 2020 06:56:39 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int n, k, num[10005] = {0};
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		num[t]++;
	}  
	int ans = 0, now = 0;
	for (int i = 0; i <= k; i++) {
		ans += num[i];
	}
	now = ans;
	for (int i = k + 1; i <= 10000; i++) {
		now += num[i];
		now -= num[i - k - 1];
		ans = max(ans, now);
	}
	cout << ans << endl;
	return 0;
}
