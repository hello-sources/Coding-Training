/*************************************************************************
	> File Name: OJ373铺地毯.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 16 Jul 2020 08:01:47 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int data[10005][4] = {0}, num, x, y;//地毯数据 
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> data[i][0]
			>> data[i][1]
			>> data[i][2]
			>> data[i][3];
		data[i][2] += data[i][0];
		data[i][3] += data[i][1];
	}
	int ans = -1;
	cin >> x >> y;
	for (int i = num; i > 0; i--) {
		if (x >= data[i][0] && x <= data[i][2] &&
			y >= data[i][1] && y <= data[i][3]) {
				ans = i;
				break;
			}
	}
	cout << ans << endl;
	return 0;
} 
