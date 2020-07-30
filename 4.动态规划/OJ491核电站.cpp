/*************************************************************************
	> File Name: OJ491核电站.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 30 Jul 2020 12:52:14 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	long long ans[55] = {1 , 2}, n, m;
	cin >> n >> m;
	for (int i = 2; i <= n; i++) {
		if (i < m) ans[i] = ans[i - 1] * 2;
		if (i == m) ans[i] = ans[i - 1] * 2 - 1;
		if (i > m) ans[i] = ans[i - 1] * 2 - ans[i - m - 1];
	}		
	cout << ans[n] << endl;
	return 0;
}
