/*************************************************************************
	> File Name: OJ578题海战.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 15 Aug 2020 08:02:30 AM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;

struct people {
	long long num1, num2;//表示前五十道，后五十道 
};

//表示对应存的题目 
long long base[55], all[55];
int n, m, k; 
people peo[105]; 

void func0() {
	int p_num;
	cin >> p_num;
	long long ans1, ans2;
	if (m > 50) {
		ans1 = all[50];
		ans2 = all[m - 50];
	} else {
		ans1 = all[m];
		ans2 = 0;
	}
	for (int i = 0; i < p_num; i++) {
		int t_peo;
		cin >> t_peo;
		ans1 &= ~peo[t_peo].num1;
		ans2 &= ~peo[t_peo].num2;
	}
	int flag = 0;
	for (int i = 1; i <= 50; i++) {
		if (ans1 & base[i]) {
			if (flag) cout << " ";
			flag = 1;
			cout << i;
		}
	}
	for (int i = 1; i <= 50; i++) {
		if (ans2 & base[i]) {
			if (flag) cout << " ";
			flag = 1;
			cout << i + 50;
		}
	}
	cout << endl;
}

void func1() {
	int p_num;
	cin >> p_num;
	long long ans1, ans2;
	ans1 = ans2 = 0xffffffffffffffff;
	for (int i = 0; i < p_num; i++) {
		int t_peo;
		cin >> t_peo;
		ans1 &= peo[t_peo].num1;
		ans2 &= peo[t_peo].num2;
	}
	int flag = 0;
	for (int i = 1; i <= 50; i++) {
		if (ans1 & base[i]) {
			if (flag) cout << " ";
			flag = 1;
			cout << i;
		}
	}
	for (int i = 1; i <= 50; i++) {
		if (ans2 & base[i]) {
			if (flag) cout << " ";
			flag = 1;
			cout << i + 50;
		}
	}
	cout << endl;
}

int main() {
	long long now = 1;
	for (int i = 0; i <= 50; i++) {
		if (i != 0) all[i] = all[i - 1] + now;
		base[i] = now;
		now *= 2;
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		map<int, int> ma;
		for (int j = 0; j < t; j++) {
			int t2;
			cin >> t2;
			if (ma[t2] == 1) continue;
			ma[t2] = 1;
			if (t2 <= 50) {
				peo[i].num1 += base[t2];
			} else {
				peo[i].num2 += base[t2 - 50];
			}
		}
	} 
	cin >> k;
	for (int i = 0; i < k; i++) {
		int t;
		cin >> t;
		if (t == 1) func1();
		else func0();
	}
	return 0;
} 
