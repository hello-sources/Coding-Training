//使用qsort进行排序
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    for (int i = 0; i < n; i++) {
        A[m + i] = B[i];
    }
    qsort(A, m + n, sizeof(int), cmp);
    return ;
}

//双指针
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int cnt = m + n - 1, i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0 && cnt >= 0) {
        if (A[i] > B[j]) {
            A[cnt--] = A[i--];
        } else {
            A[cnt--] = B[j--];
        }
    }
    while (i >= 0 && cnt >= 0) {
        A[cnt--] = A[i--];
    }
    while (j >= 0 && cnt >= 0) {
        A[cnt--] = B[j--];
    }
    return ;
}
