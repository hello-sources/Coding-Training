/*************************************************************************
	> File Name: OJ253奶牛晒太阳.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 22 Aug 2020 08:13:14 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 2500
struct Data {
	int x, y;
} cows[MAX_N + 5];
int cnt[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
	if (a.y - b.y) return a.y < b.y;
	return a.x > b.x;
}

int main() {
	int c, l;
	cin >> c >> l;
	for (int i = 0; i < c; i++) {
		cin >> cows[i].x >> cows[i].y;
	} 
	for (int i = 0, a, b; i < l; i++) {
		cin >> a >> b;
		cnt[a] += b;
	} 
	sort(cows, cows + c, cmp);
	int ans = 0;
	for (int i = 0; i < c; i++) {
		for (int j = cows[i].x; j <= cows[i].y; j++) {
			if (cnt[j] == 0) continue;
			ans++;
			cnt[j] -= 1;
			break;
		}
	}
	cout << ans << endl;
	return 0;
} 
