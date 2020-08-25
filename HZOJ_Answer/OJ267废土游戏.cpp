/*************************************************************************
	> File Name: OJ267废土游戏.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 26 Aug 2020 07:14:18 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000
int f[MAX_N + 5][MAX_N + 5]; 
int s[MAX_N + 5], top = -1;
int l[MAX_N + 5], r[MAX_N + 5];

int solve(int *arr, int n) {
	arr[0] = -1;//表示最小值 
	s[++top] = 0;//栈中存的就是arr数组的下标 
	for (int i = 1; i <= n; i++) {
		while (arr[i] <= arr[s[top]]) --top;
		l[i] = s[top];
		s[++top] = i;
	}
	top = -1;
	arr[n + 1] = -1;
	s[++top] = n + 1;
	for (int i = n; i >= 1; i--) {
		while (arr[i] <= arr[s[top]]) --top;
		r[i] = s[top];
		s[++top] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, (r[i] - l[i] - 1) * arr[i]);
	}
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char ch[5];
			cin >> ch;
			f[i][j] = (ch[0] == 'F');
			if (f[i][j] == 1) f[i][j] += f[i - 1][j];
		}
	}
	int ans = 0; 
	for (int i = 1; i <= n; i++) {
		ans = max(ans, solve(f[i], m));
	}
	cout << 3 * ans << endl;
	return 0;
}
