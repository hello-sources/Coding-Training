/*************************************************************************
	> File Name: OJ38兔子繁殖.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 17 Aug 2020 09:21:05 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
//递推公式f[n] = f[n - 1] + f[n - 2] 

//开发一个结构体类型 ，继承一个vector类型 
struct BigInt : vector<int> {
	BigInt (int x) {//BigInt的构造函数 
		push_back(x);//放到数组的最后一位 
		normal();//处理进位 
	}
	
	//大整数加法问题，重载运算符，当前大整数加上b这个大整数 
	BigInt operator+(const BigInt &b) {// 
		BigInt ret = (*this);//结果大整数等于当前大整数  
		for (int i = 0; i < b.size(); i++) {
			if (i < ret.size()) {
				ret[i] += b[i];
			} else {//表示传入的大整数要更长 
				ret.push_back(b[i]);
			}
		}
		ret.normal();
		return ret;
	}
	
	//处理当前大整数进位问题 
	void normal() {
		for (int i = 0; i < size(); i++) {
			if (at(i) < 10) continue;
			if (i + 1 == size()) push_back(0);
			at(i + 1) += at(i) / 10;
			at(i) %= 10;
		}
		return ;
	}
};

//重载"<<"运算符，第一个参数表示运算符，第二个参数表示大整数类型 
ostream &operator<<(ostream &out, const BigInt &a) {
	for (int i = a.size() - 1; i >= 0; i--) {
		out << a[i];
	}
	return out;
}
int main() {
	int n;
	BigInt a = 1, b = 1, c = 0;
	cin >> n;
	while (n--) {
		c = a + b;
		a = b;
		b = c;
	}
	cout << a << endl;	
	return 0;
}
