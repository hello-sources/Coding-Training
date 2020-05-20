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
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (i == j) continue;
			for (int k = 3; k <= 17; k++) {
				for (int l = 1; l <= k; l++) {
					if (j == 0 && l == 1) continue;
					if (i == 0 && l != 1) break;
					long long t = 0;
					for (int m = 1; m <= k; m++) {
						if (m != l) {
							t = t * 10 + i;
						} else {
							t = t * 10 + j;
						}
					}
					if (t >= a && t <= b) ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
