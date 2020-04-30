/*************************************************************************
    > File Name: 最长公共子序列.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 30 Apr 2020 08:25:43 PM CST
 ************************************************************************/


#include <iostream>
using namespace std;
#define MAX_N 1000
int dp[MAX_N + 5][MAX_N + 5];
string s1, s2;

int main() {
	cin >> s1 >> s2;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (s1[i - 1] - s2[j - 1]) continue;
			dp[i][j] = dp[i - 1][j - 1] + 1;
		}
	}
	cout << dp[s1.size()][s2.size()] << endl;
	return 0;
}
