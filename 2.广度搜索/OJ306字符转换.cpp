/*************************************************************************
	> File Name: OJ306字符转换.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 15 Jul 2020 09:33:10 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

//搜索节点结构体，字符串，以及需要几步 
struct node {
	string str;
	int num;
};

//起点终点以及替换规则 
string str1, str2, rpl[7][2];
queue<node> que;
map<string, int> ma;//去重 
int n;

int main() {
	cin >> str1 >> str2;
	while (cin >> rpl[n][0] >> rpl[n][1]) {
		n++;//循环输入对应的替换规则 
	}
	que.push({str1, 0});//起点插入队列 
	ma[str1] = 1;//标记起点 
	while (!que.empty()) {
		for (int i = 0; i < n; i++) {//对应n中转换规则 
			int j = 0;//j代表搜索到哪里了 
			while (1) {
				node temp2 = que.front(); 
				long long x = temp2.str.find(rpl[i][0], j);//每次找一个位置看能否替换前面字符串 
				j = x + 1;
				if (x != string::npos) {//找着，就替换为后面字符串 
					temp2.str.replace(x, rpl[i][0].size(), rpl[i][1]);
					temp2.num++;//步数加一 
					if (temp2.str == str2) {
						cout << temp2.num << endl;//如果是终点直接输出 
						return 0;
					}
					if (temp2.num > 10) continue;//步数超过10步，样例不要 
					if (ma[temp2.str] == 1) continue;//如果已经遍历，字符串也不要 
					ma[temp2.str] = 1;//标记已经用过了 
					que.push(temp2);//入队 
				} else {
					break;
				}
			}
		}
		que.pop();//一个规则结束了，队首元素出队 
	}
	cout << "NO ANSWER!" << endl;
	return 0;
}
