/*************************************************************************
    > File Name: num_triangle.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 30 Apr 2020 06:33:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000

int f[MAX_N + 5][MAX_N + 5];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> f[i][j];
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
		}
	}
	cout << f[1][1] << endl;
	return 0;
}
