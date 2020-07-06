/*************************************************************************
	> File Name: OJ227_64位整数乘法.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 06 Jul 2020 10:30:15 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

long long quick_mul(long long a, long long b, long long p) {
	long long tmp = a, ans = 0;
	while (b) {
		if (b & 1) ans = (ans + tmp) % p;
		tmp = tmp * 2 % p;
		b >>= 1;
	}
	return ans;
}

int main() {
	long long a, b, p;
	cin >> a >> b >> p;
	cout << quick_mul(a, b, p) << endl; 

	return 0;
} 
