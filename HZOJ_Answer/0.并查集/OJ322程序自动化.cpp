/*************************************************************************
	> File Name: OJ322程序自动化.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 13 Sep 2020 06:09:32 AM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;
#define MAX_N 1000000

struct UnionSet {
	int fa[(MAX_N << 1) + 5];
	void init(int n) {
		while (n--) fa[n + 1] = n + 1;
	}
	int get(int x) {
		return (fa[x] = (x - fa[x] ? get(fa[x]) : x));
	}
	void merge(int a, int b) {
		fa[get(a)] = get(b);
	} 
}; 

UnionSet u;

struct Data {
	int e, i, j;
} arr[MAX_N + 5];

void solve() {
	map<int, int> ind;
	int cnt = 0;
	int n, m;
	cin >> n >> m;
	u.init(2 * n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].e >> arr[i].i >> arr[i].j;
		if (ind.find(arr[i].i) == ind.end()) ind[arr[i].i] = (++cnt);
		if (ind.find(arr[i].j) == ind.end()) ind[arr[i].j] = (++cnt);
		arr[i].i = ind[arr[i].i];
		arr[i].j = ind[arr[i].j];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i].e == 0) continue;
		u.merge(arr[i].i, arr[i].j);
	}
	int flag = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i].e == 1) continue;
		flag = (u.get(arr[i].i) != u.get(arr[i].j));
	}
	cout << (flag ? "Yes" : "No") << endl;
	return ;
}

int main() {
	int tcase;
	cin >> tcase;
	while (tcase--) solve();	
	return 0;
} 
