/*************************************************************************
	> File Name: OJ292数独游戏_优化.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 02 Sep 2020 08:58:27 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
string s;
int x[9], y[9], z[9], gx, gy, gz;

void get(int i) {
	gx = i / 9, gy = i % 9, gz = (gx / 3) * 3 + gy / 3;
	return ; 
}

void work(int i, int num) {
	get(i);
	x[gx] ^= (1 << num);
	y[gy] ^= (1 << num);
	z[gz] ^= (1 << num);
	return ;
}

int cnt_one(int x) {
	int ret = 0;
	while (x) ret += 1, x &= (x - 1);
	return ret;
}

bool dfs(int cnt) {
	if (cnt == 0) return true;
	int ind = -1, k = 100;
	for (int i = 0; i < 81; i++) {
		if (s[i] != '.') continue;
		get(i);
		int temp = 9 - cnt_one(~(x[gx] & y[gy] & z[gz]));
		if (temp < k) {
			ind = i;
			k = temp;
		}
	}
	for (int i = 1; i <= 9; i++) {
		get(ind);
		if ((x[gx] & y[gy] & z[gz]) & (1 << i)) {
			work(ind, i);
			s[ind] = i + '0';
			if (dfs(cnt - 1)) return true;
			s[ind] = '.';
			work(ind, i);
		}
	}
	return false;
}

void Sudoku() {
	for (int i = 0; i < 9; i++) x[i] = y[i] = z[i] = -1;
	int cnt = 0;
	for (int i = 0; i < 81; i++) {
		if (s[i] == '.') {
			cnt += 1;
			continue;
		}
		work(i, s[i] - '0');
	}
	dfs(cnt); 
	cout << s << endl; 
	return ;
}

int main() {
	while (cin >> s && s[0] != 'e') Sudoku();
	return 0;
} 
