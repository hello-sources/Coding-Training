#include <iostream>
using namespace std;

char ans[2200][2200];//ȫ�ֱ���Ĭ������Ϊ0 
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729, 2187};

//�ȴ�ӡ����ͼ�Σ��������Ͻ����꣬�Լ���Ӧ��Сn 
void func(int x, int y, int n) {
	if (n == 1) {
		ans[x][y] = 'X';//��λ���߳�Ϊ1ֱ�����X 
		return ;
	}
	func(x, y, n - 1);//�����ǰͼ�� 
	func(x, y + num[n] / 3 * 2, n - 1);//�����ǰͼ���ұ�ͼ�� 
	func(x + num[n] / 3 * 2, y, n - 1);//�����ǰλ����һ��ͼ�� 
	func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);//��������½�ͼ�� 
	func(x + num[n] / 3, y + num[n] / 3, n - 1);//�������ͼ�� 
}

int main() {
	func(1, 1, 7);//��Ӧ��ӡ����ͼ�� 
	int n;
	while (cin >> n) {
		if (n == -1) break;//�ж��Ƿ��ʽ������� 
		for (int i = 1; i <= num[n]; i++) {
			for (int j = 1; j <= num[n]; j++) {
				//��鵱ǰλ�õ��ַ��ǲ���X������Ǿ�ֱ����� 
				if (ans[i][j] == 'X') cout << 'X';
				else cout << ' ';
				//��������ո� 
			}
			cout << endl;//ÿһ������֮��������з� 
		}
		cout << "-" << endl;
	}
	return 0;
}
