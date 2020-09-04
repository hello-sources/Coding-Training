/*************************************************************************
	> File Name: OJ296公交车.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 04 Sep 2020 08:02:46 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 300
int cnt[MAX_N + 5];
int n, ans = 17;

struct Data {
	int s, b, z;
}; 

vector<Data> a;

inline bool check(int i, int j) {
	for (i; i < 60; i += j) {
		if (cnt[i] == 0) return false;
	}
	return true;
}

inline void add_cnt(int i, int j, int val) {
	for (; i < 60; i += j) cnt[i] += val;
	return ;
}

void dfs(int ind, int k, int c) {
	if (k >= ans) return ;
	if (c == 0) {
		ans = k;
		return ;
	}
	for (int i = ind; i < a.size(); i++) {
		if (c / a[i].z + k >= ans) break;
		if (!check(a[i].s, a[i].b)) continue;
		add_cnt(a[i].s, a[i].b, -1);
		dfs(i, k + 1, c - a[i].z);
		add_cnt(a[i].s, a[i].b, 1);
	}
}

bool cmp(Data a, Data b) {
	return a.z > b.z;
}

int main() {
	cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		cnt[x] += 1; 
	} 
	//预处理合法的公交线路 
	for (int i = 0; i < 60; i++) {
		if (cnt[i] == 0) continue;
		for (int j = i + 1, J = 60 - i; j < J; j++) {
			if (!check(i, j)) continue;
			a.push_back({i, j, (59 - i) / j + 1});
		}
	}
	//对公交线路排序 
	sort(a.begin(), a.end(), cmp);
	//继承式搜索
	dfs(0, 0, n);
	cout << ans << endl; 
	return 0;
} 
