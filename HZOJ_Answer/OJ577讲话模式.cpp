/*************************************************************************
	> File Name: OJ577讲话模式.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 10 Aug 2020 08:18:29 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>
using namespace std;

void check(string &str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 'a' - 'A';
		}
	}
}

int main() {
	map<string, int> m;
	string str, ans;
	int ans_cnt;
	while (cin >> str) {
		check(str);
		m[str]++;
		if (m[str] > ans_cnt) {
			ans_cnt = m[str];
			ans = str;
		} else if (m[str] == ans_cnt && str < ans) {
			ans_cnt = m[str];
			ans = str;
		}
	}	
	cout << ans << " " << ans_cnt << endl;
	return 0;
}
