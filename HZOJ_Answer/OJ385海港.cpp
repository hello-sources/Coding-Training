/*************************************************************************
	> File Name: OJ385海港.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 19 Jul 2020 09:39:35 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct person {
	int t, c;
	//人作为结构体存储进来，有到达时间以及国籍 
};
int nation[100005];

int main() {
	queue<person> que;
	int n, con = 0;//表示船只以及答案 
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t, num;//读入到达时间t以及船上有多少人 
		scanf("%d%d", &t, &num);
		while (!que.empty()) {//处理时间超过一天的人 
			person temp = que.front(); 
			if (t - temp.t < 86400) break;//在一天之中的话 
			que.pop();//直接pop出去， 
			nation[temp.c]--;//国家对应人数减一 
			if (nation[temp.c] == 0) con--;//如果对应国家人数为0了，国籍减一 
		}
		for (int j = 0; j < num; j++) {
			int temp;
			scanf("%d", &temp);//读入国籍 
			que.push({t, temp});//插入队列，时间，以及国籍 
			if (nation[temp] == 0) con++;//初始国家人数为0，则国籍加一 
			nation[temp]++;//国家人数也加一 
		} 
		printf("%d\n", con);
	}
	
	return 0;
}
