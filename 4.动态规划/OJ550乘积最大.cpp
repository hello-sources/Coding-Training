/*************************************************************************
	> File Name: OJ550乘积最大.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 20 Oct 2020 07:48:39 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 50
#define MAX_K 10 

struct BigInt : public vector<int> {
	BigInt() { push_back(0); }
	BigInt(string str) {
		for (int i = str.size() - 1; i >= 0; i--) {
			push_back(str[i] - '0');
		}
		normal();
	}
	BigInt operator*(const BigInt &obj) {
		BigInt ret;
		for (int i = 0; i < size(); i++) {
			for (int j = 0; j < obj.size(); j++) {
				if (ret.size() == i + j) ret.push_back(0);
				ret[j + i] += at(i) * obj.at(j); 
			}
		}
		ret.normal();
		return ret;
	}
	bool operator>(const BigInt &obj) {
		if (size() - obj.size()) return size() > obj.size();
		for (int i = size() - 1; i >= 0; i--) {
			if (at(i) - obj.at(i)) return at(i) > obj.at(i);
		}
		return false;
	}
	void normal() {
		for (int i = 0; i < size(); i++) {
			if (at(i) < 10) continue;
			if (i == size() - 1) push_back(0);
			at(i + 1) += at(i) / 10;
			at(i) %= 10;
		}
		while (size() && at(size() - 1) == 0) pop_back();
		if (size() == 0) push_back(0);
		return ; 
	}
};

BigInt dp[MAX_N + 5][MAX_K + 5];

ostream &operator<<(ostream &out, const BigInt &obj) {
	for (int i = obj.size() - 1; i >= 0; i--) {
		out << obj[i];
	}
	return out;
} 

int main() {
	int n, k;
	string str;
	cin >> n >> k >> str;
	for (int i = 1; i <= n; i++) dp[i][1] = str.substr(0, i);
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= k + 1; j++) {
			for (int t = 1; t < i; t++) {
				if (dp[t][j - 1] * str.substr(t, i - t) > dp[i][j]) {
					dp[i][j] = dp[t][j - 1] * str.substr(t, i - t);
				}
			}
		}
	}
	cout << dp[n][k + 1] << endl;
	return 0;
} 
