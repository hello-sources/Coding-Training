#include <iostream>
#include <cstdio>
#define max_n 1000
using namespace std;

int val[max_n + 5][max_n + 5] = {0};
int keep[max_n + 5][max_n + 5] = {0};

int dfs(int i, int j, int n) {
    if (i + 1 == n) return val[i][j];
    if (keep[i][j] != 0) return keep[i][j];
    int val1 = dfs(i + 1, j, n);
    int val2 = dfs(i + 1,j + 1,n);
    return keep[i][j] = (val1 > val2 ? val1 : val2) + val[i][j];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d",&val[i][j]);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            val[i][j] += max(val[i + 1][j],val[i + 1][j + 1]);
        }
    }
    //printf("%d\n",dfs(0, 0, n));
    printf("%d\n",val[0][0]);
    return 0;
}
