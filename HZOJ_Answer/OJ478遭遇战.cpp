/*************************************************************************
	> File Name: OJ478遭遇战.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 26 Jul 2020 10:27:21 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int t, mmap[1005][1005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
	cin >> t;
	while (t--) {
		int n, x1, y1, d1, x2, y2, d2;
		cin >> n >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;
		x1++; x2++; y1++; y2++;
		mmap[x1][y1] += 1;
		mmap[x2][y2] += 2;
		int flag1 = 0, flag2 = 0;
		while (1) {
			if (flag1 >= 4 && flag2 >= 4) {
				cout << -1 << endl;
				break;
			}
			if (x1 == x2 && y1 == y2) {
				cout << x1 - 1 << " " << y1 - 1 << endl;
				break;
			}
			while (1) {
				int tx1 = x1 + dir[d1][0], ty1 = y1 + dir[d1][1]; 
				if (flag1 == 4) {
					break;
				}
				if (!(mmap[tx1][ty1] & 1) && tx1 > 0 && ty1 > 0 && tx1 <= n && ty1 <= n) {
					x1 = tx1;
					y1 = ty1;
					mmap[x1][y1] += 1;
					flag1 = 0;
					break;
				} else {
					d1++;
					flag1++;
					if (d1 == 4) d1 = 0;
				}
			}
			while (1) {
				int tx2 = x2 + dir[d2][0], ty2 = y2 + dir[d2][1]; 
				if (flag2 == 4) {
					break;
				}
				if (!(mmap[tx2][ty2] & 2) && tx2 > 0 && ty2 > 0 && tx2 <= n && ty2 <= n) {
					x2 = tx2;
					y2 = ty2;
					mmap[x2][y2] += 2;
					flag2 = 0;
					break;
				} else {
					d2--;
					flag2++;
					if (d2 == -1) d2 = 3;
				}
			}
		}
		memset(mmap, 0, 1005 * 1005 * sizeof(int));
	}
	return 0;
} 
