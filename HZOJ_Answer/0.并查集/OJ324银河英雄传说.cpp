/*************************************************************************
	> File Name: OJ324银河英雄传说.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 14 Sep 2020 06:18:20 AM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define MAX_N 500000
struct UnionSet {
	int fa[MAX_N + 5], val[MAX_N + 5], size[MAX_N + 5];
	void init(int n) {
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
			val[i] = 0;
			size[i] = 1;
		}
	}
	int get(int x) {
		if (x == fa[x]) return x;
		int root = get(fa[x]);
		val[x] += val[fa[x]];
		return fa[x] = root;
	}
	void merge(int a, int b) {
		int aa = get(a), bb = get(b);
		if (aa == bb) return ;
		fa[aa] = bb;
		val[aa] = size[bb];
		size[bb] += size[aa];
		return ;
	}
}; 

UnionSet u;

int main() {
	//std::ios::sync_with_stdio(false);//关闭同步流 
	int n, a, b;
	char str[10];
	scanf("%d", &n);
	u.init(n);
	for (int i = 0; i < n; i++) {
		scanf("%s%d%d", str, &a, &b);
		switch (str[0]) {
			case 'M': {
				u.merge(a, b);
				break;
			}
			case 'C': {
				if (u.get(a) != u.get(b)) {
					printf("-1\n");
				} else {
					printf("%d\n", abs(u.val[a] - u.val[b]) - 1);
				}
				break;
			}
		}
	}
	return 0;
} 
