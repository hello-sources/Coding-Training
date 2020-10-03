/*************************************************************************
	> File Name: OJ358金字塔.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 04 Oct 2020 07:16:25 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
#define MAX_N 300
#define MOD_NUM 1000000000
long long dp[MAX_N + 5][MAX_N + 5];

int main() {
	string s;
	cin >> s; 
	long long n = s.size();
	for (long long i = 0; s[i]; i++) dp[i][i] = 1;
	for (long long l = 2; l <= s.size(); l++) {
		for (long long i = 0, I = n - l; i <= I; i++) {
			long long j = i + l - 1;
			dp[i][j] = 0;
			if (s[i] - s[j]) continue;
			for (long long k = i + 2; k <= j; k++) {
				if (s[k] - s[j]) continue;
				dp[i][j] += dp[i + 1][k - 1] * dp[k][j];
				dp[i][j] %= MOD_NUM; 
			}
		}
	}
	cout << dp[0][s.size() - 1] << endl;
	return 0;
} 
