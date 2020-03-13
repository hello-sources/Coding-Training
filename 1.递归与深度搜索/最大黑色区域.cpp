#include <iostream>
using namespace std;

int n, m, cnt = 1, ans = 1;
char num[105][105];
int dir[4][2] = {1, 0, 0, 1, 0, -1, -1, 0};

int calc(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (num[tx][ty] == '1') {
			num[tx][ty] = '0';
			if (calc(tx, ty)) cnt++;
		}
	}
	return cnt;
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
			if (num[i][j] == '0') continue;
			num[i][j] = '0';
			ans = max(calc(i, j), ans);
			cnt = 1;
		}
	}
	cout << ans << endl;
	return 0;
}
