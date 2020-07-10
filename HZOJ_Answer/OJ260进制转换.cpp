/*************************************************************************
	> File Name: OJ260进制转换.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 10 Jul 2020 07:22:29 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

//两个整型数组分别转换为十进制以及目标进制数组
//两个字符串数组，一个读入数，一个存答案 
int to_10[150], to_64[150];
char s[1005], ans[1005];

//初始化数组
void init() {
	int t = 0;
	for (int i = '0'; i <= '9'; i++) {
		to_10[i] = t;
		to_64[t] = i;
		t++;
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		to_10[i] = t;
		to_64[t] = i;
		t++;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		to_10[i] = t;
		to_64[t] = i;
		t++;
	}
}

int main() {
	init();//初始化数组 
	int a, b;
	cin >> a >> b >> s;
	cout << a << " " << s << endl << b << " ";
	int len = strlen(s), t = strlen(s), mmax;
	//分别记录字符串长度，当前串长度，还有大整数最大位数 
	for (int i = 0; t; i++) {
		int k = 0;//同余定理 
		for (int j = len - t; j < len; j++) {
			k = k * a + to_10[s[j]];
			s[j] = to_64[k / b];//进来的位数把商存起来 
			k %= b;//模除（同余定理） 
		}
		ans[i] = to_64[k];//求出这一位的余数 
		while (t > 0 && s[len - t] == '0') {
			t--;//处理位数，转换为目标进制 
		}
		mmax = i;//更新一下长度 
	}
	for (int i = mmax; i >= 0; i--) {
		cout << ans[i];//逆序输出答案 
	}
	cout << endl;
	return 0;
}
