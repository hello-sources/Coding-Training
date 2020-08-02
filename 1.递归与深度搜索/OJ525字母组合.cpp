/*************************************************************************
	> File Name: OJ525字母组合.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 02 Aug 2020 05:06:21 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, k, cnt, ans_cnt;
char ans[30]; 

//递归枚举所有情况 
int func(char start) {
	for (char a = start; a <= 'A' + n - 1; a++) {
		ans[ans_cnt++] = a;
		cnt++;//表示对应位置的组合 
		if (cnt == k) {
			for (int i = 0; i < ans_cnt; i++) {
				cout << ans[i];
			}
			return 1; 
		}
		if (func(a + 1)) return 1;
		ans_cnt--;
	}
	return 0;
}

int main() {
	cin >> n >> k;
	func('A');
	return 0;
}
