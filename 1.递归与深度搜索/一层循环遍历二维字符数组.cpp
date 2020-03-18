/*************************************************************************
    > File Name: 一层循环遍历二维字符数组.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 18 Mar 2020 10:41:55 PM CST
 ************************************************************************/
nclude <iostream>
using namespace std;

int n, m;
char mmap[55][55];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> (&mmap[i][1]);
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << mmap[i][j];
		}
		cout << endl;
	}
	return 0;
} 

