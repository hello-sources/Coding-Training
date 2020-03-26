#include <iostream>
#include <algorithm>
using namespace std;
 
//atime�洢�ڽӾ��󣬵�һά��ʾ��˭��ans�洢���ߵ��յ����з�ʽ��ʱ�� 
int n, m, atime[2][20][20], ans[2][100000], ans_num[2];

void func(int people, int locate, int cost) {
	if (locate == n) {
		ans[people][ans_num[people]] = cost;
		ans_num[people]++;
		return ;
	}
	for (int i = locate + 1; i <= n; i++) {
		if (atime[people][locate][i]) {
			func(people, i, cost + atime[people][locate][i]);
		}
	}
}

//ͬ��Ҳ��ʹ���ڽӾ��� 
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		atime[0][a][b] = atime[0][b][a] = c;
		atime[1][a][b] = atime[1][b][a] = d;
	}
	func(0, 1, 0);//��¼0�����ڵ�λ�� 
	func(1, 1, 0);//��¼1�����ڵ�λ�� 
	sort(ans[0], ans[0] + ans_num[0]);
	sort(ans[1], ans[1] + ans_num[1]);
	for (int i = 0; i < ans_num[0]; i++) {
		for (int j = 0; j < ans_num[1]; j++) {
			if (ans[0][i] == ans[1][j]) {
				cout << ans[0][i] << endl;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
