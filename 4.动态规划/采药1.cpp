#include <iostream>
using namespace std;

int t, m, mtime[105], mval[105], ans[1005];

int main() {
	cin >> t >> m;
	for (int i = 1; i <= m; i++) {
		cin >> mtime[i] >> mval[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = t; j > 0; j--) {
			if (j < mtime[i]) {
				break;
			} else {
				ans[j] = max(ans[j], ans[j - mtime[i]] + mval[i]);
			}
		}
	}
	cout << ans[t] << endl;
	return 0;
} 
