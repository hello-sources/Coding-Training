/*************************************************************************
	> File Name: OJ554零件分组.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 22 Oct 2020 07:09:33 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct Data {
	int x, y;
} arr[1005];

int len[1005], ans = 0;

bool cmp(const Data &a, const Data &b) {
	if (a.x - b.x) return a.x < b.x;
	return a.y < b.y;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i].x >> arr[i].y;
	sort(arr + 1, arr + 1 + n, cmp);
	len[++ans] = arr[1].y;
	for (int i = 2; i <= n; i++) {
		int x = 0;
		for (int j = 1; j <= ans; j++) {
			if (len[j] > arr[i].y) continue;
			if (x == 0) x = j;
			else if (len[x] < len[j]) x = j;
		}
		if (x == 0) len[++ans] = arr[i].y;
		else len[x] = arr[i].y;
	}
	cout << ans << endl;
	return 0;
} 
