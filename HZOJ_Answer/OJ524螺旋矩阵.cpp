/*************************************************************************
	> File Name: OJ524螺旋矩阵.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 02 Aug 2020 04:54:15 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	int t;//表示第几圈 
	if (x + y <= (n + 1) / 2 * 2) {
		t = min(x, y);
	} else {
		for (int i = 1; i <= n; i++) {
			if (x - n + i >= 1 || y - n + i >= 1) {
				t = i;
				break;
			}
		}
	}
	int s = 1, tn = n - 1;//起点与每圈的边长 
	for (int i = 1; i < t; i++) {
		s += tn * 4;
		tn -= 2;
	}
	if (x == t) {
		cout << s + y - t  << endl;
	} else if (y == t + tn) {
		cout << s + tn + x - t << endl;
	} else if (x == t + tn) {
		cout << s + 3 * tn - (y - t) << endl;
	} else {
		cout << s + 4 * tn - (x - t) << endl;
	}
	return 0;
} 
