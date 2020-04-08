#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct watermallon {
	int num;
	int sum;
};

bool cmp1(watermallon a,watermallon b) {
	return a.sum < b.sum;
}

int y[100005];
int main() {
	int m,n,i,j;
	watermallon w[100005];
	scanf("%d%d",&m,&n);
	for(i = 0;i < m;i++) {
		scanf("%d",&w[i].sum);
		w[i].num = i + 1;
	}

	for(i = 0;i < n;i++) {
		scanf("%d",&y[i]);
	}
	sort(w,w + m,cmp1);
	for(i = 0;i < n;i++) {
		int l = 0;
		int r = m;
		while(l < r) {
			int mid = l + (r - l) / 2;
			if(w[mid].sum == y[i]) {
				printf("%d\n",w[mid].num);
				break;
			}
			else if(w[mid].sum < y[i]) l = mid + 1;
			else r = mid;
		}
		if(l >= r)
			printf("0\n");
	}
	
	return 0;
}
