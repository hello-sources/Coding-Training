/*************************************************************************
	> File Name: P4826最大生成树.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 14 Aug 2020 07:43:56 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm> 
using namespace std;

struct edge {
	int from, to;
	long long val;
};

bool cmp(edge a, edge b) {
	return a.val > b.val;	
} 

edge edg[2000005];
long long n, ans, edg_cnt, num[2005], my_union[2005], already = 1;

int find_fa(int x) {
	if (my_union[x] == x) {
		return x;
	}
	return my_union[x] = find_fa(my_union[x]); 
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		my_union[i] = i;
		cin >> num[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			edg[edg_cnt].from = i;
			edg[edg_cnt].to = j;
			edg[edg_cnt].val = num[i] ^ num[j];
			edg_cnt++;
		}
	}
	sort(edg, edg + edg_cnt, cmp);
	for (int i = 0; i < edg_cnt; i++) {
		int fa = find_fa(edg[i].from), fb = find_fa(edg[i].to);
		if (fa != fb) {
			my_union[fa] = fb;
			already++;
			ans += edg[i].val;
			if (already == n) {
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
} 
