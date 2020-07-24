/*************************************************************************
	> File Name: OJ474四级考试.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 24 Jul 2020 12:23:48 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;

//先把整数部分相乘，同时记录对应的应该有多少位小数 
int n;
char ch_right[105];
int ans[250] = {1, 1};

int mul(char *a) {
	if (a[0] == '0') {
		for (int i = 1; i <= ans[0]; i++) {
			ans[i] = 0;
		}
		ans[0] = 1;
		return -1;
	}
	if (strlen(a) == 4) {
		for (int i = ans[0]; i > 0; i--) {
			ans[i + 2] = ans[i];
		}
		ans[1] = ans[2] = 0;
		ans[0] += 2;
		return 0;
	}
	int temp[10] = {strlen(a) - 1};
	for (int i = 1, j = temp[0] - 1; i <= temp[0]; i++, j--) {
		temp[i] = a[j] - '0';
	}
	int chengji[250] = {max(ans[0], temp[0])};
	for (int i = 1; i <= ans[0]; i++) {
		for (int j = 1; j <= temp[0]; j++) {
			chengji[i + j - 1] += ans[i] * temp[j];
		}
	}
	for (int i = 1; i <= chengji[0]; i++) {
		chengji[i + 1] += chengji[i] / 10;
		chengji[i] %= 10;
	}
	for (int i = chengji[0] + 1; chengji[i]; i++) {
		chengji[0] = i;
		chengji[i + 1] += chengji[i] / 10;
		chengji[i] %= 10;
	}
	for (int i = chengji[0]; i > 0; i--) {
		ans[i] = chengji[i];
	}
	ans[0] = chengji[0];
	return 0;
}

int main() {
	cin >> n >> ch_right;
	for (int i = 0; i < n; i++) {
		char a[5], b[5], c[5], d[5];
		cin >> a >> b >> c >> d;
		int flag = 0;
		switch (ch_right[i]) {
			case 'A' : flag = mul(a); break;
			case 'B' : flag = mul(b); break;
			case 'C' : flag = mul(c); break;
			case 'D' : flag = mul(d); break;
		}
		if (flag == -1) {
			cout << 0 << endl;
			return 0;
		}
	}
	char real_ans[250] = {0};
	if (ans[n * 2 + 1]) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = n * 2, j = 0; i > 0; i--, j++) {
		real_ans[j] = ans[i] + '0';
	}
	for (int i = strlen(real_ans) - 1; i > 0; i--) {
		if (real_ans[i] != '0') break;
		real_ans[i] = '0'; 
	}
	cout << "0." << real_ans << endl;
	
	return 0;
} 
