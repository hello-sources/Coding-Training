#include <iostream>
using namespace std;

int n, weight[20], cnt, mark[1005] = {1};

//�������������ֱ��ǿ�ʼ�����Լ������� 
void func(int start, int sum) {
	if (!mark[sum]) {
		cnt++;
		mark[sum] = 1;
		//���в��ز������ж϶�Ӧ����������Ƿ�Ϊ1
		//������ж�Ӧ�����һ 
	}
	for (int i = start; i < n; i++) {
		sum += weight[i];
		func(i + 1, sum);//�ݹ� 
		sum -= weight[i];//���� 
	}
	return ;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	func(0, 0);
	cout << cnt << endl;
	return 0; 
} 
