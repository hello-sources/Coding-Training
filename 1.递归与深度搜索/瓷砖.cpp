#include <iostream>
using namespace std;

int h, w, sx, sy, cnt = 1;
char cp[55][55];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int func(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (cp[tx][ty] == '.') {
			cp[tx][ty] = '^';
			if (func(tx, ty)) cnt++; 
		}
	}
	return cnt;
}

int main() {
	cin >> h >> w;
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			cin >> cp[i][j];
			if (cp[i][j] == '@') {
				sx = i;
				sy = j;
			}
		}
	}
	cout << func(sx, sy) << endl;
	return 0;
} 
