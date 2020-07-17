/*************************************************************************
	> File Name: OJ376机器翻译.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 17 Jul 2020 12:37:50 PM CST
 ************************************************************************/

#include <iostream>
#include <queue> 
using namespace std;


int main() {
	queue<int> que;//需要一个队列存储单词 
	int n, m, ans = 0;//ans表示查词的次数 
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int t, f = 0;
		cin >> t;
		for (int j = 0; j < que.size(); j++) {
			//遍历队列里面是否有对应的单词 
			if (que.front() == t) {
				f = 1;//如果有对应flag标记为1 
			}
			que.push(que.front());//把队首放到队尾 
			que.pop();//队首出队 
		}
		if (f == 0) {//flag还是0，则表示得插入队列 
			ans++;
			que.push(t);
			if (que.size() > n) {
				que.pop();//判断大小是否超出内存限制 
			}  
		}
	}
	cout << ans << endl;
	return 0;
}
