#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int num, val;
};

node wm[100005];

bool cmp(node a, node b) {
	return a.val < b.val;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> wm[i].val;
		wm[i].num = i + 1;
	}
	sort(wm, wm + n, cmp);
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		int l = 0, r = n - 1, f = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (wm[mid].val == t) {
				cout << wm[mid].num << endl;
				f = 1;
				break;
			}
			if (wm[mid].val < t) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		if (f == 0) {
			cout << 0 << endl;
		}
	}
	
	return 0;
} 
