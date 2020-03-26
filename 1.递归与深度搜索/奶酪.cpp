#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

//�������λ�����꣬��ʼ���飬�յ����� 
int t, n, h, r, qiu[1005][3], low[1005], low_num, up[1005], arr[1005][1005], check[1005];

int func(int now) {
	if (up[now] == 1) return 1;//�����Ӧ������ֵ��1�����ҵ��˳��� 
	for (int i = 1; i <= n; i++) {//�����յ㣬�ͱ���������ͨ��δ�������ĵ� 
		if (arr[now][i] && check[i] == 0) {
			check[i] = 1;//������鶨��Ϊ1�� 
			if (func(i)) return 1;//�������� 
		}
	}
	return 0;
}

int main() {
	cin >> t;
	while (t--) {//t���������룬���� 
		memset(low, 0, sizeof(low));
		memset(up, 0, sizeof(up));
		memset(arr, 0, sizeof(arr));
		memset(check, 0, sizeof(check));
		low_num = 0;
		cin >> n >> h >> r;
		for (int i = 1; i <= n; i++) {
			cin >> qiu[i][0] >> qiu[i][1] >> qiu[i][2];//����������� 
			if (qiu[i][2] <= r) {//����С�ڰ뾶����������� 
				low[low_num] = i;
				low_num++;
			}
			if (qiu[i][2] + r >= h) {//�ж��յ㣬����h������� 
				up[i] = 1;
			}
			//����ߵ����⣬�жϱ��Ƿ���ͨ 
			for (int j = 1; j < i; j++) {
				int t0 = qiu[i][0] - qiu[j][0];//x
				int t1 = qiu[i][1] - qiu[j][1];//y 
				int t2 = qiu[i][2] - qiu[j][2];//z
				if (sqrt(t0 *t0 + t1 * t1 + t2 * t2) <= 2 * r) {
					arr[i][j] = arr[j][i] = 1;//����ͨ���ڽӾ����Ӧ������Ϊ1 
				}
			}
		}
		//����������飬�ж��Ƿ��ҵ����ɹ�����һ�����Yes 
		int flag = 0;
		for (int i = 0; i <= low_num; i++) {
			if (check[i] == 0) {
				check[i] = 1;
				if (func(i)) {
					cout << "Yes" << endl;
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) {
			cout << "No" << endl;
		}
	}
	return 0;
} 
