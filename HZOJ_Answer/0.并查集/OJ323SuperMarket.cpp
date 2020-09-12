/*************************************************************************
	> File Name: OJ323SuperMarket.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 13 Sep 2020 06:31:07 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10000

struct Data {
	int d, p;
} arr[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
	if (a.p - b.p) return a.p > b.p;
	return a.d > b.d;
}

struct UnionSet {
	int fa[MAX_N + 5];
	void init(int n) {
		for (int i = 0; i <= n; i++) fa[i] = i;
	}
	int get(int x) {
		return (fa[x] = (x - fa[x] ? get(fa[x]) : x));
	}
	void merge(int a, int b) {
		fa[get(a)] = get(b);
	}
};

UnionSet u;

int main() {
	int n;
	while (cin >> n) {
		u.init(MAX_N);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].p >> arr[i].d;
		}
		sort(arr, arr + n, cmp);
		for (int i = 0; i < n; i++) {
			if (u.get(arr[i].d)) {
				int d = u.get(arr[i].d);
				ans += arr[i].p;
				u.merge(arr[i].d, arr[i].d - 1);
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
