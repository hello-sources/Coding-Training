/*************************************************************************
	> File Name: OJ252天才ACM_倍增+归并.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 21 Aug 2020 09:13:34 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 500000 
long long arr[MAX_N + 5];
long long temp[MAX_N + 5];

inline long long S(long long x) { return x * x; }

bool is_val(long long l, long long mid, long long r, long long k, long long m) {
	long long spd = 0;
	for (int i = mid + 1; i <= r; i++) temp[i] = arr[i];
	sort(temp + mid + 1, temp + r + 1);
	int l1 = l, r1 = mid, l2 = mid + 1, r2 = r, cnt = l;
    while (l1 <= r1 || l2 <= r2) {
        if (l2 > r2 || (l1 <= r1 && arr[l1] <= temp[l2])) {
            temp[cnt++] = arr[l1++];
        } else {
            temp[cnt++] = temp[l2++];
        }
    }
    for (int i = l, j = r; i < j && m; i++, j--, m--) {
        spd += S(temp[i] - temp[j]);
        if (spd > k) return false;
    }
    return true;
}

long long get_next(long long l, long long r, long long k, long long m) {
    long long head = l, tail = l, c = 1, flag = 0;
    while (c) {
        if (tail + c <= r && is_val(head, tail, tail + c, k, m)) {
            tail += c;
            for (int i = head; i <= tail; i++) arr[i] = temp[i];
        } else {
            flag = 1;
        }
        if (flag) c /= 2;
        else c *= 2;
    }
    return tail + 1;
}

void solve() {
	long long n, m, k, pre = 0, cnt = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	while (pre < n) {
		pre = get_next(pre, n, k, m);
		cnt += 1;
	}
	cout << cnt << endl;
	return ;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
