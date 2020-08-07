/*************************************************************************
	> File Name: OJ562找数.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 07 Aug 2020 01:57:21 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
 
int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		ans ^= t;
	}
	cout << ans << endl;
	return 0;
}
