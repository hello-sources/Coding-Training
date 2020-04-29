#include <iostream>
#include <cstdio>
using namespace std;

int n, m, num[1005][1005], down[1005][1005], up[1005][1005], mmax[1005], mmax_ind[1005], mmax2[1005];


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &num[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			down[i][j] = max(down[i - 1][j - 1], down[i - 1][j]) + num[i][j];
		}
	}
	for (int i = n; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			up[i][j] = max(up[i + 1][j + 1], up[i + 1][j]) + num[i][j];
		}
	}
	for (int i = 2; i <= n; i++) {
		int ind1 = 0, ind1_max = 0, ind2_max = 0;
		for (int j = 1; j <= i; j++) {
			int t = down[i][j] + up[i][j] - num[i][j];
			if (t > ind1_max) {
				ind1_max = t;
				ind1 = j;
			}
		}
		for (int j = 1; j <= i; j++) {
			int t = down[i][j] + up[i][j] - num[i][j];
			if (t > ind2_max && j != ind1) {
				ind2_max = t;
			}
		}
		mmax[i] = ind1_max;
		mmax_ind[i] = ind1;
		mmax2[i] = ind2_max;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == 1 && b == 1) {
			printf("-1\n");
			continue;
		}
		if (mmax_ind[a] == b) {
			printf("%d\n", mmax2[a]);
		} else {
			printf("%d\n", mmax[a]);
		}
	}
	return 0;
} 
