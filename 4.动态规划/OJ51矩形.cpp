/*************************************************************************
    > File Name: OJ51矩形.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 13 May 2020 12:19:42 AM CST
 ************************************************************************/


#include <iostream>
using namespace std;
#define MAX_N 1000
int f[MAX_N + 5];//记录当前位置的矩形的值 
int a[MAX_N + 5];//向上数连续白色格子的数量 
int s[MAX_N + 5], top = -1;//单调栈 

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	a[m + 1] = -1;
	f[m + 1] = 0;
	for (int i = 1; i <= n; i++) {
		//记录每一个位置的白色矩形的个数，读一行数据 
		for (int j = 1, val; j <= m; j++) {
			cin >> val;
			if (val == 1) a[j] += 1;
			else a[j] = 0; 
		}
		//读入一行之后对于每一行进行处理 
		top = -1;//单调栈每一次都得清空 
		s[++top] = m + 1;
		for (int j = m; j >= 1; j--) {
			while (a[s[top]] >= a[j]) top--;
			f[j] = (s[top] - j) * a[j] + f[s[top]];	
			//每一列位置可以抽象为一根木板，连续公共长度相等的木板加上对应之后值 
			f[j] %= 100007;
			s[++top] = j;
			ans += f[j];
			ans %= 100007;
		}
	}
	cout << ans << endl;
	return 0;
}
