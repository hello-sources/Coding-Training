#include <iostream>
using namespace std;
#define MAX_N 500000
int a[MAX_N + 5], b[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int p = 1, top1 = 0, top2 = 0;
    while (p < n) {
        while (top1 != -1 && a[p] <= a[top1]) --top1;
        while (top2 != -1 && b[p] <= b[top2]) --top2;
        if (top1 - top2) break;
        a[++top1] = a[p];
        b[++top2] = b[p];
        p++;
    }
    cout << p << endl;
    return 0;
}