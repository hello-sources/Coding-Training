#include <iostream>
using namespace std;

int all, n, w[100005], v[100005], ans[10000], ind;

int main() {
	cin >> all >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		for (int j = 0; j < z; j++) {
			ind++;
			w[ind] = x;
			v[ind] = y;
		}
	}
	for (int i = 1; i <= ind; i++) {
		for (int j = all; j >= w[i]; j--) {
			ans[j] = max(ans[j], ans[j - w[i]] + v[i]);
		}
	}
	cout << ans[all] << endl;
	return 0;
}
