#include <iostream>
using namespace std;

int n, m, ans;
int num[105][105];
int dir[4][2] = {1, 0, 0, 1, 0, -1, -1, 0};

int calc(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (num[tx][ty]) {
			num[tx][ty] = 0;
			if (calc(tx, ty)) return 1;
		}
	}
	return 0;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> num[i][j];
		}
	} 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!num[i][j]) continue;
			num[i][j] = 0;
			calc(i, j);
			ans += 1;
		}
	}
	cout << ans << endl;
	return 0;
}
