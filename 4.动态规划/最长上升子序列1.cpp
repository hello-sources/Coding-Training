#include <iostream>
using namespace std;
#define MAX_N 1000000
#define INF 0x3f3f3f3f

int dp[MAX_N + 5];
int len[MAX_N + 5], ans = 0; 
int a[MAX_N + 5];

int bs(int *arr, int l, int r, int x) {
	if (l == r) return l; 
	int mid = (l + r) >> 1;
	if (arr[mid] < x) return bs(arr, mid + 1, r, x);
	return bs(arr, l, mid, x);
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 1;
		len[i] = INF; 
	}
	len[++ans] = a[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = bs(len, 1, ans + 1, a[i]);
		len[dp[i]] = a[i];
		ans = max(dp[i], ans);
	}
	cout << ans << endl;
	return 0;
}
 
