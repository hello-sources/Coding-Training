#include <iostream>
#include <algorithm>
using namespace std;

int n, m, money[30], val[30], ans[30][30005];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> money[i] >> val[i];
		val[i] *= money[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (j < money[i]) {
				ans[i][j] = ans[i - 1][j];
			} else {
				ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - money[i]] + val[i]);
			}	
		}
	}
	cout << ans[m][n] << endl;
	return 0;
}
