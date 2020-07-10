/*************************************************************************
	> File Name: OJ282最大异或对.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 11 Jul 2020 07:56:13 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

//字典树节点 
struct node {
	int num;//保存数 
	node *next[2];//对应左右两个指针 
};

int number[32];

//插入表示从哪插入，插入的值，还有位 
node *insert(node *x, int y, int cnt) {
	if (x == NULL) {
		x = new node();//初始化一个节点 
	}
	if (cnt == -1) {
		x->num = y; //表示插完了 
	} else {
		//如果与上是1就往x->next[1]插入 
		if (y & number[cnt]) {
			x->next[1] = insert(x->next[1], y, cnt - 1);
		} else {//否则就往x->next[0]插入 
			x->next[0] = insert(x->next[0], y, cnt - 1);
		}
	}
	return x;
}

//查找 
int find(node *x, int y, int cnt) {
	if (cnt == -1) {
		return x->num;//表示找到这个数，直接返回这个数 
	}
	//如果y & number[cnt]表示y这一位为1，且对应0不为空，
	//另一种情况就是x->next[1]为空的 
	if (((y & number[cnt]) && x->next[0] != NULL) || x->next[1] == NULL) {
		return find(x->next[0], y, cnt - 1);//递归的往x->next[0]找 
	} else {
		return find(x->next[1], y, cnt - 1);//递归的往x->next[1]找 
	}
}

//初始化数组，按照2的倍数乘 
void init() {
	int t = 1;
	for (int i = 0; i <= 31; i++) {
		number[i] = t;
		t *= 2;
	}
}

int main() {
	init();//数组初始化 
	node *root = NULL;
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;//临时变量 
		cin >> t;
		root = insert(root, t, 31);//把t插入字典树中，最后一个数表示插到第几位 
		int x = find(root, t, 31);//找和t差的最多的数 
		ans = max(ans, t ^ x);//找到对应最大的异或差 
	}
	cout << ans << endl;
	
	return 0;
}
