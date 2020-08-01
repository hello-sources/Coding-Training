/*************************************************************************
	> File Name: OJ522多项式求值.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 01 Aug 2020 08:53:34 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int n, x, ans = 0;
	cin >> n >> x;
	int indx = 1;
	for (int i = 0; i <= n; i++) {
		int temp;
		cin >> temp;
		ans += temp * indx;
		indx *= x;
	}
	cout << ans << endl;
	return 0;
}
