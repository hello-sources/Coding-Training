/*************************************************************************
	> File Name: OJ566上网统计.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 08 Aug 2020 11:52:36 AM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <string> 
using namespace std;

string s[1001][5000];//一维表示用户名，二维表示网页 
string raw[1005];//记住用户名的字符串 
int num[1005];//表示存每个用户的访问网页数 
int n, m, total;
map<string, int> ma;//把字符串转化为int整型 

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (ma[s1] == 0) {//对应字符串没有出现过 
			total++;//计数器加一 
			ma[s1] = total;
			raw[total] = s1;//存入用户名数组中 
		}
		int x = ma[s1];//编号出现很多次 
		s[x][num[x]] = s2;//访问的网页 
		num[x]++;//表示网页字符串多一个 
	}
	for (int i = 1; i <= total; i++) {
		cout << raw[i];//输出人名 
		int x = ma[raw[i]];
		for (int j = 0; j < num[i]; j++) {
			cout << " " << s[x][j];//循环输出对应的网页 
		}
		cout << endl;
	}
	return 0;
}
