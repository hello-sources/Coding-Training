/*************************************************************************
    > File Name: 优雅数.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 20 May 2020 08:57:10 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

long long a, b, ans;

int main() {
	cin >> a >> b;
	for (int i = 0; i <= 9; i++) {//一堆数
		for (int j = 0; j <= 9; j++) {//一个数
			if (i == j) continue;
			for (int k = 3; k <= 17; k++) {//数的总长度
				for (int l = 1; l <= k; l++) {//一个数的位置
					if (j == 0 && l == 1) continue;//前置零的情况
					if (i == 0 && l != 1) break;//都continue也行
					long long t = 0;
					for (int m = 1; m <= k; m++) {
						//构造一个优雅数
						if (m != l) {
							t = t * 10 + i;
						} else {
							t = t * 10 + j;
						}
					}
					if (t >= a && t <= b) ans++;//找出对应范围内的数
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
