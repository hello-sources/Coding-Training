/*************************************************************************
	> File Name: OJ586排列.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 16 Aug 2020 08:50:49 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int check(int x, int y, int z) {
	int num[10] = {1};
	while (x) {
		num[x % 10]++;
		num[y % 10]++;
		num[z % 10]++;
		x /= 10;
		y /= 10;
		z /= 10;
	}
	for (int i = 1; i <= 9; i++) {
		if (num[i] != 1) return 0;
	}
	return 1;
}

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	for (int i = 111; i < 1000; i++) {
		int j = i * y / x;
		int k = i * z / x;
		if (check(i, j, k)) {
			cout <<  i << " " << j << " " << k << endl;
		}
	} 
	return 0;
} 
