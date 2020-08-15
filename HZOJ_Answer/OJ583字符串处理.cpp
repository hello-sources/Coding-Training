/*************************************************************************
	> File Name: OJ583字符串处理.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 15 Aug 2020 09:00:42 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int ans;
string str;

void func1(int l, int r) {
	for (int i = 0; 1; i++) {
		if (l - i < 0 || str[l - i] != str[r + i]) break;
		ans++;
	}
}

void func() {
	for (int i = 0; i < str.size(); i++) {
		func1(i, i);//如果是单数，重点是i 
		func1(i, i + 1);//如果是偶数，终点有两个 
	}
}

int main() {
	while (cin >> str) {
		func();
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
