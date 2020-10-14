/*************************************************************************
	> File Name: OJ494拔河.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 15 Oct 2020 06:42:28 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	long long n, ans;
	cin >> n;
	if (n % 2 == 0) {
		ans = n / 2 * ((n - 2) / 2) * ((n - 2) / 2);
	} else {
		ans = n * (n - 1) * (n - 3) / 8;
	}
	cout << ans << endl;
	return 0;
} 
