/*************************************************************************
	> File Name: OJ543分书问题.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 04 Aug 2020 02:24:35 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, check[25], ans;
char arr[25][25]; 

void func(int x) {
	if (x == n + 1) {
		ans++;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == 0 && arr[x][i] == '1') {
			check[i] = 1;
			func(x + 1);
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	func(1);
	cout << ans << endl;
	return 0;
}
