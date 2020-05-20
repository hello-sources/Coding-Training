/*************************************************************************
    > File Name: 三角形个数.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 20 May 2020 07:51:27 PM CST
 ************************************************************************/


#include <iostream>
using namespace std;

int n, ans; 

int main() {
	cin >> n;
	for (int i = 1; i <= n / 3; i++) {
		for (int j = i; j <= (n - i) / 2; j++) {
			int y = n - i - j;
			if (i + j > y) ans++;
		}
	}
	cout << ans << endl;
	return 0;
} 
