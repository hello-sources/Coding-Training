/*************************************************************************
	> File Name: OJ355划分大理石.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 01 Oct 2020 07:06:09 AM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int a[7];
int val[1000], cnt = 0;
int f[120005];

int solve() {
	memset(f, 0, sizeof(f));
	cnt = 0;
	int flag = 0;
	for (int i = 1; i <= 6; i++) cin >> a[i], flag += a[i] * i;
	if (flag == 0) return 0;
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= a[i]; j <<= 1) {
			val[cnt++] = j * i;
			a[i] -= j;
		}
		if (a[i]) val[cnt++] = a[i] * i;
	}
	f[0] = 1;
	for (int i = 0; i < cnt && !(flag % 2); i++) {
		for (int j = flag / 2; j >= val[i]; j--) {
			f[j] |= f[j - val[i]];
		}
	}
	cout << (f[flag / 2] ? "Can" : "Can't") << endl;
	return 1;
} 

int main() {
	while (solve()) ;
	return 0;
} 
