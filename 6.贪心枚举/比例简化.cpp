/*************************************************************************
    > File Name: 比例简化.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 20 May 2020 07:46:58 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int a, b, l, aa, bb;
double raw, now = 9999999;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	cin >> a >> b >> l;
	raw = (double)a / b;
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++) {
			double t = (double)i / j;
			if (t >= raw && t - raw < now - raw && gcd(i, j) == 1) {
				now = t;
				aa = i;
				bb = j;
			}
		}
	}
	cout << aa << " " << bb << endl;
	return 0;
} 
