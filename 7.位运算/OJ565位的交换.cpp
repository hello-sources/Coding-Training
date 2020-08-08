/*************************************************************************
	> File Name: OJ565位的交换.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 08 Aug 2020 11:27:34 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = ((n << 16) & 0xffff0000) | ((n >> 16) & 0x0000ffff);
	cout << ans << endl;
	return 0;
} 
