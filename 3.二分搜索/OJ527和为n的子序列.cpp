/*************************************************************************
	> File Name: OJ527和为n的子序列.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 01 Aug 2020 09:04:08 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		long long l = 1, r = i;
		while (l <= r) {
			long long mid = (l + r) >> 1;
			long long temp = (mid + i) * (i - mid + 1) >> 1;
			if (temp == n) {
				for (long long j = mid; j <= i; j++) {
					if (j != mid) cout << " ";
					cout << j;
				}
				return 0;
			}
			if (temp > n) {
				l = mid + 1;//由于后面的的位置固定了所有得向右边移动 
			} else {
				r = mid - 1;//否则向左边移动 
			}
		}
	} 
	return 0;
} 
