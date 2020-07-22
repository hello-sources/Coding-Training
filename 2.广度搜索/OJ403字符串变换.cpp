/*************************************************************************
	> File Name: OJ403字符串变换.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 22 Jul 2020 04:36:18 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

struct node {
	string str;
	int num;//num表示需要几步 
};
string str1, str2, rpl[7][2];//替换字符串 
queue<node> que;
map<string, int> ma;//去重 
int n; 

int main() {
	cin >> str1 >> str2;
	for (int i = 0; cin >> rpl[i][0]; i++) {//不知道有多少个能输入的时候输入 
		cin >> rpl[i][1];
		n = i + 1;
	}
	que.push({str1, 0});
	ma[str1] = 1;//起点搜过了 
	while (!que.empty()) {
		for (int i = 0; i < n; i++) {//对应n种变换规则 
			//建立一个临时变量 
			node temp = que.front();
			for (int j = 0; temp.str[j]; j++) {
			//遍历字符串按照字符串每一个地方为起点 
				node temp2 = que.front();
				//如果不等于没找着，说明找到了 
				if (temp2.str.find(rpl[i][0], j) != string::npos) {
					//替换对应字符串 
					temp2.str.replace(temp2.str.find(rpl[i][0], j), rpl[i][0].size(), rpl[i][1]);
					temp2.num++;
					if (temp2.str == str2) {
						cout << temp2.num << endl;//找到答案直接输出 
						return 0;
					}
					if (temp2.num > 10) continue;//十步以内直接continue 
					if (ma[temp2.str] != 0) continue;//如果找过了continue 
					ma[temp2.str] = 1;//置为1，插入队列里面去 
					que.push(temp2);
				}
			}
			que.pop();
		}
	}
	cout <<  "NO ANSWER!" << endl;
	return 0;
} 
