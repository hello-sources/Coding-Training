/*************************************************************************
	> File Name: OJ350Trip.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 27 Sep 2020 08:46:04 AM CST
 ************************************************************************/

#include <iostream>
#include <set>
#include <string>
using namespace std;
#define MAX_N 80
struct SET {
	void operator+=(const SET &obj) {
		const set<string> &tmp = obj.s;
		for (auto iter = tmp.begin(); iter != tmp.end(); iter++) {
			s.insert(*iter);
		}
		return ;
	}
	SET operator+(char ch) {
		SET ret;
		if (s.size() == 0) ret.s.insert(string("") + ch);
		for (auto iter = s.begin(); iter != s.end(); iter++) {
			ret.s.insert((*iter) + ch);
		}
		return ret;
	}
	set<string> s;
};
int dp[MAX_N + 5][MAX_N + 5];
SET s[MAX_N + 5][MAX_N + 5];

ostream &operator<<(ostream &out, SET &obj) {
	for (auto iter = obj.s.begin(); iter != obj.s.end(); iter++) {
		out << *iter << endl;
	}
	return out;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (dp[i][j] < dp[i - 1][j]) {
				dp[i][j] = dp[i - 1][j];
				s[i][j] = s[i - 1][j];
			} else if (dp[i][j] == dp[i - 1][j]) {
				s[i][j] += s[i - 1][j];
			}
			if (dp[i][j] < dp[i][j - 1]) {
				dp[i][j] = dp[i][j - 1];
				s[i][j] = s[i][j - 1];
			} else if (dp[i][j] == dp[i][j - 1]) {
				s[i][j] += s[i][j - 1];
			}
			if (s1[i - 1] - s2[j - 1]) continue;
			if (dp[i - 1][j - 1] + 1 > dp[i][j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				s[i][j] = s[i - 1][j - 1] + s1[i - 1];
			} else if (dp[i - 1][j - 1] + 1 == dp[i][j]) {
				s[i][j] += s[i - 1][j - 1] + s1[i - 1];
			}
		}
	}
	int n = s1.size(), m = s2.size();
	cout << s[n][m] << endl;
	return 0;
} 
