#include <iostream>
using namespace std;

int n, num[1005][1005], ans[1005][1005];


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> num[i][j];
		}
	}
	for (int i = n; i >=1; i--) {
		for (int j = 1; j <= i; j++) {
			ans[i][j] = max(ans[i + 1][j + 1], ans[i + 1][j])  + num[i][j];
		}
	}
	cout << ans[1][1] << endl;
	return 0;
} 
