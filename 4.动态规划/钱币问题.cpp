#include <iostream>
using namespace std;
#define MAX_N 20
#define MAX_M 100000

int M[MAX_N + 5] = {0};
int D[MAX_M + 5] = {0};

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> M[i];
	}
	D[0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = M[i]; j <= n; j++) {
			D[j] += D[j - M[i]];
			D[j] %= 9973;
		}
	}
	cout << D[n] << endl;
	return 0;
}
