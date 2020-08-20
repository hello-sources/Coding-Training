/*************************************************************************
	> File Name: OJ239不规则的街道.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 20 Aug 2020 08:24:56 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio> 
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef std::pair<LL, LL> PII;

PII solve(int n, LL id) {
	if (n == 1) {
		if (id == 1) return PII(0, 0);
		else if (id == 2) return PII(0,1);
		else if (id == 3) return PII(1, 1);
		else return PII(1, 0); 
	}
	LL L = 1LL << (n - 1);
	LL block = 1LL << (2 * n - 2);
	if (id <= block) {
		PII tmp = solve(n - 1, id);
		return PII(tmp.second, tmp.first);//(y, x)
	} else if (id <= 2 * block) {
		PII tmp = solve(n - 1, id - block);
		return PII(tmp.first, tmp.second + L);//(x, y + L)
	} else if (id <= 3 * block) {
		PII tmp = solve(n - 1, id - block * 2);
		return PII(tmp.first + L, tmp.second + L);//(x + L, y+ L);
	} else {
		PII tmp = solve(n - 1, id - block * 3);
		return PII(2 * L - tmp.second - 1, L - tmp.first - 1);//(2L - y - 1, L - x - 1);
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		LL s, d;
		cin >> n >> s >> d;
		PII pos1 = solve(n, s);
		PII pos2 = solve(n, d);
		LL x = pos1.first - pos2.first;
		LL y = pos1.second - pos2.second;
		printf("%.0f\n", 10 * sqrt(x * x + y * y));
	}
	
	return 0;
} 
