/*************************************************************************
    > File Name: OJ342照相的排列数.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 13 May 2020 12:31:13 AM CST
 ************************************************************************/


#include <iostream>
#include <cstring>  
using namespace std;
long long a[5];

long long solve(long long k) {
	long long a[5] = {0}, full_size = 1;
	for (long long i = 0; i < k; i++) {
		cin >> a[i];//每排人数 
		full_size *= (a[i] + 1); //计算五维数组大小，用人数连乘表示用于初始化五维数组 
	}
	long long f[a[0] + 1][a[1] + 1][a[2] + 1][a[3] + 1][a[4] + 1];//这样声明是为了减少空间支出 
	memset(f, 0, sizeof(long long) * full_size); 
	f[0][0][0][0][0] = 1;//初始化状态就是1 
	for (long long i1 = 0; i1 <= a[0]; i1++) {
	for (long long i2 = 0; i2 <= a[1]; i2++) {
	for (long long i3 = 0; i3 <= a[2]; i3++) {
	for (long long i4 = 0; i4 <= a[3]; i4++) {
	for (long long i5 = 0; i5 <= a[4]; i5++) {	
		//根据左到右身高依次递减每一列从后到前身高也递减可知 
		long long val = f[i1][i2][i3][i4][i5];
		if (i1 < a[0] && i1 >= i2 && i1 >= i4 && i1 >= i5) 
			f[i1 + 1][i2][i3][i4][i5] += val;
		if (i2 < a[1] && i2 >= i3 && i2 >= i4 && i2 >= i5) 
			f[i1][i2 + 1][i3][i4][i5] += val;
		if (i3 < a[2] && i3 >= i4 && i3 >= i5) 
			f[i1][i2][i3 + 1][i4][i5] += val;
		if (i4 < a[3] && i4 >= i5) 
			f[i1][i2][i3][i4 + 1][i5] += val;
		if (i5 < a[4]) 
			f[i1][i2][i3][i4][i5 + 1] += val;
	}}}}}
	cout << f[a[0]][a[1]][a[2]][a[3]][a[4]] << endl;
	return 0;
} 

int main() {
	long long k;
	while (cin >> k) {
		if (k == 0) break;
		solve(k);
	}
	return 0;
} 
