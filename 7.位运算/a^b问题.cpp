/*************************************************************************
    > File Name: a^b问题.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Mon 25 May 2020 10:50:54 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

long long quick_mod(long long a, long long b, long long p) {
	long long temp = a, ans = 1;
	while (b) {
		if (b & 1) ans = ans * temp % p;
		temp = temp * temp % p;
		b >>= 1;
	}
	return ans % p;
}

int main() {
	long long a, b, p;
	cin >> a >> b >> p;
	cout << quick_mod(a, b, p) << endl;
	
	return 0;
}
