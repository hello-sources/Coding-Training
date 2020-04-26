#include <iostream>
using namespace std;

long long f[2][3][3];

long long P(int wallsize, int num) {
	int i, j, k, l;
	if (wallsize == 1) return 0;
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			if (i == j) continue;
			f[0][i][j] = 1;
		}
	}
	for (i = 3; i <= wallsize; i++) {
		for (j = 0; j < num; j++) {
			for (k = 0; k < num; ++k) {
				f[i % 2][k][j] = 0;
				for (l = 0; l < num; l++) {
					if (l == j) continue;
					f[i %2][k][j] += f[(i % 2) ^ 1][k][l];
				}
			}
		}
	}
	long long ans = 0;
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			if (i == j) continue;
			ans += f[wallsize % 2][i][j];
		}
	}
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << P(n, k) << endl;
	return 0;
}
