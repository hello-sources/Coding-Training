/*************************************************************************
	> File Name: OJ292数独游戏.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 02 Sep 2020 08:56:59 AM CST
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

bool dfs(int ind) {
	if (ind == 81) return true;
	if (s[ind] != '.') {
		return dfs(ind + 1);
	}
	for (int i = 1; i <= 9; i++) {
		get(ind);
		if ((x[gx] & y[gy] & z[gz]) & (1 << i)) {
			work(ind, i);
			s[ind] = i + '0';
			if (dfs(ind + 1)) return true;
			work(ind, i);
		}
	}
	return false;
}

void Sudoku() {
	for (int i = 0; i < 9; i++) x[i] = y[i] = z[i] = -1;
	for (int i = 0; i < 81; i++) {
		if (s[i] == '.') continue;
		work(i, s[i] - '0');
	}
	dfs(0); 
	cout << s << endl; 
	return ;
}

int main() {
	while (cin >> s && s[0] != 'e') Sudoku();
	return 0;
} 
