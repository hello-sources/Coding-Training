/*************************************************************************
	> File Name: OJ256国王游戏.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 23 Aug 2020 09:58:26 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 1000
int a[MAX_N + 5], b[MAX_N + 5];
int ind[MAX_N + 5]; 

bool cmp(int i, int j) {
	return a[i] * b[i] < a[j] * b[j];
}

struct BigInt  {
	BigInt(int x) {
		num.push_back(x);
		proccess_digit();
	}
	BigInt(vector<int> ret) : num(ret) {}
	BigInt operator/(int x) {
		int temp = 0, i = num.size() - 1;
		while (i >= 0 && temp * 10 + num[i] < x) temp = temp * 10 + num[i--]; 
		if (i < 0) return 0;
		vector<int> ret(i + 1);
		while (i >= 0) {
			temp = temp * 10 + num[i];
			ret[i] = temp / x;
			temp %= x;
			i--;
		}
		return ret;
	}
	void proccess_digit() {
		for (int i = 0; i < num.size(); i++) {
			if (num[i] < 10) continue;
			if (i + 1 == num.size()) num.push_back(0);
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
		return ;
	}
	bool operator>(BigInt &obj) {
		if (num.size() - obj.num.size()) return num.size() > obj.num.size();
		for (int i = num.size() - 1; i >= 0; i--) {
			if (num[i] - obj.num[i]) return num[i] > obj.num[i];
		}
		return false;
	}
	void operator*=(int x) {
		for (int i = 0; i < num.size(); i++) num[i] *= x;
		proccess_digit();
		return ;
	}
	vector<int> num;
};

ostream &operator<<(ostream &out, const BigInt &obj) {
	for (int i = obj.num.size() - 1; i >= 0; i--) {
		out << obj.num[i];
	}
	return out;
} 

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) cin >> a[i] >> b[i], ind[i] = i;
	sort(ind + 1, ind + 1 + n, cmp);
	BigInt p = a[ind[0]], ans = 0;
	for (int i = 0; i <= n; i++) {
		BigInt temp = p / b[ind[i]];
		if (temp > ans) ans = temp;
		p *= a[ind[i]];
	}
	cout << ans << endl;
	return 0;
} 
