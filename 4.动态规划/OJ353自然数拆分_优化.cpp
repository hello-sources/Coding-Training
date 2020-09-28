/*************************************************************************
	> File Name: OJ353自然数拆分_优化.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 29 Sep 2020 07:52:25 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 4000
#define MOD_NUM 2147483648
long long f[MAX_N + 5]; 

int main() {
	long long n;
	cin >> n; 
	f[0] = 1;
	for (long long i = 1; i <= n; i++) {
		for (long long j = i; j <= n; j++) {
			f[j] += f[j - i];
			f[j] %= MOD_NUM;
		}
	}
	cout << f[n] - 1 << endl;
	return 0;
} 
