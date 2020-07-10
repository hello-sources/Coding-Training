/*************************************************************************
	> File Name: OJ281前缀统计.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 11 Jul 2020 07:26:29 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//字典树节点结构体变量 
struct node {
	int flag;//表示到这为止有多少字符串 
	node *next[27];//输入只有26个小写字母 
};

//参数1往哪插，参数2插入什么 
node *insert(node *x, char *s) {
	if (x == NULL) {//根节点为空 
		x = new node();//就初始化一个 
	}
	if (s[0] == 0) {
		x->flag++;//插入成功对应flag++ 
	} else {
		//否则对应s[0] - 'a'位置上插入，位置是s + 1位置 
		x->next[s[0] - 'a'] = insert(x->next[s[0] - 'a'], s + 1);
	}
	return x;
}

//参数1在哪里找，参数2找什么 
int find(node *x, char *s) {
	if (x == NULL) return 0;//根节点为空，对应为0 
	if (s[0] == 0) return x->flag;//说明到头了，直接返回字符串 
	//朴素情况就是x->next[s[0] - 'a']往下找，下一个位置s + 1 
	return x->flag + find(x->next[s[0] - 'a'], s + 1);
}

int main() {
	node *root = NULL;//字典树根节点 
	char str[100005];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		root = insert(root, str);
		//每次插入都是往哪插，赋值给根节点 
	} 
	for (int i = 0; i < m; i++) {
		cin >> str;
		cout << find(root, str) << endl;//对应查找字符串 
	}
	
	return 0;
} 
