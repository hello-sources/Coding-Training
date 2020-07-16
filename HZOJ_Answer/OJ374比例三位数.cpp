/*************************************************************************
	> File Name: OJ374比例三位数.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 16 Jul 2020 08:10:39 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int check(int a1, int a2, int a3) {
	int num[10] = {0};
	for (int i = 0; i < 3; i++) {
		num[a1 % 10] = 1; a1 /= 10;
		num[a2 % 10] = 1; a2 /= 10;
		num[a3 % 10] = 1; a3 /= 10;
	}
	for (int i = 1; i < 10; i++) {
		if (num[i] == 0) return 0;
	}
	return 1;
}

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int f = 0;
	for (int i = 123; i < 1000; i++) {
		int l1 = i;
		int l2 = i * y / x;
		int l3 = i * z / x;
		if (l2 > 999 || l3 > 999) break;
		if (check(l1, l2, l3)) {
			cout << l1 << " " << l2 << " " << l3 << endl;
			f = 1;
		}
	}
	if (f == 0) {
		cout << "NO" << endl;
	}
	
	return 0;
} 
