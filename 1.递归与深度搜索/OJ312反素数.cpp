/*************************************************************************
	> File Name: OJ312反素数.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 07 Sep 2020 06:52:34 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
long long prime[11] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23,29}; 
long long ans = 1, cnt = 1;

void dfs(int k, long long num, long long n, int fcnt) {
	if (fcnt > cnt || (fcnt == cnt && num < ans)) {
		ans = num;
		cnt = fcnt;
	}
	for (long long i = num * prime[k], j = 1; i <= n; i *= prime[k], j++) {
		dfs(k + 1, i, n, fcnt * (j + 1));
	}
	return ;
}

int main() {
	long long n;
	cin >> n;
	dfs(1, 1, n, 1);
	cout << ans << endl;
	return 0;
} 
