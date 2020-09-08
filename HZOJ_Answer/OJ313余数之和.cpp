/*************************************************************************
	> File Name: OJ313余数之和.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 08 Sep 2020 11:03:51 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define P(a) printf("%s = %d\n", #a, a);

int main() {
	long long n, k, sum = 0; 
	cin >> n >> k;
	for (long long i = 2; i <= n;) {
		if (k < i) {
			sum += k * (n - i + 1);
			break;
		}
		long long y = k % i;
		P(y);
		long long x = k / i;
		P(x);
		long long t = y / x + 1;
		P(t);
		if (n - i + 1 < t) t = n - i + 1;
		long long a0 = y - (t - 1) * x, an = y;
		sum += (a0 + an) * t >> 1;
		i += t;	
	}
	cout << sum << endl;
	return 0;
} 
