/*************************************************************************
	> File Name: OJ320青蛙约会.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 12 Sep 2020 06:06:16 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

long long ex_gcd(long long a, long long b, long long &x, long long &y) {
	if (!b) {
		x = 1, y =0;
		return a;
	}
	long long ret = ex_gcd(b, a % b, y, x);
	y -= a / b * x;
	return ret;
}

int main() {
	long long x, y, m, n, l;
	cin >> x >> y >> m >> n >> l;
	long long a = m - n, b = y - x; 
	if (a < 0) a = -a, b = -b;
	if (b < 0) b += l;
	long long t1, t2, ret = ex_gcd(a, l, t1, t2);
	if (b % ret) {
		cout << "Impossible" << endl;
		return 0;
	}
	long long val = l / ret;
	t1 *= (b / ret);
	t1 = (t1 % val + val) % val;
	cout << t1 << endl;
	return 0;
} 
