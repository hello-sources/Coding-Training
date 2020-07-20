/*************************************************************************
	> File Name: OJ396填涂颜色.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 20 Jul 2020 08:27:38 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//把所有边为0的数都连起来，然后输出里面数值为0的点位2 
int n, mmap[35][35] = {3};
int dir[4][2] = {//方向数组 
	0, 1,
	1, 0,
	0, -1,
	-1, 0
};

void func(int x0, int y0) {
	for (int i = 0; i < 4; i++) {
		int x = x0 + dir[i][0];
		int y = y0 + dir[i][1];
		if (x > n + 1 || y > n + 1 || x < 0 || y < 0) continue;
		if (mmap[x][y] == 0) {
			mmap[x][y] = 3;
			func(x, y);//递归搜索这个点 
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mmap[i][j];
		}
	}
	func(0, 0);//开始搜索，只用搜索最外面那一圈0 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j != 1) {
				cout << " ";
			}
			if (mmap[i][j] == 3) {
				cout << 0;
			} else if (mmap[i][j] == 1) {
				cout << 1;
			} else {
				cout << 2;
			}
		}
		cout << endl;
	}
	
	return 0;
} 
