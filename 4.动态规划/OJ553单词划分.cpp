/*************************************************************************
	> File Name: OJ553单词划分.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 21 Oct 2020 07:14:15 AM CST
 ************************************************************************/

#include <iostream>
#include <set> 
using namespace std;
#define MAX_N 100
set<string> words;
int dp[MAX_N + 5];

int main() {
	string str, str_a;
	int n;
	cin >> str >> n;
	for (int i = 0; i < n; i++) {
		cin >> str_a;
		words.insert(str_a);
	}	
	dp[0] = 0;
	for (int i = 0; str[i]; i++) dp[i + 1] = str.size() + 1;
	for (int i = 1; i <= str.size(); i++) {
		for (int j = 1; j <= i; j++) {
			string s = str.substr(i - j, j);
			if (words.find(s) == words.end()) continue;
			dp[i] = min(dp[i], dp[i - j] + 1);
		}
	}
	cout << dp[str.size()] << endl;
	return 0;
} 
