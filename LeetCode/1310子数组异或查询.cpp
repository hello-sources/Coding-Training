/**
 * Q(left,right)=xors[left]⊕xors[right+1]
 * **/
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int sum[arrSize + 1];
    sum[0] = 0;
    for (int i = 0; i < arrSize; i++) {
        sum[i + 1] = sum[i] ^ arr[i];
    }
    int *ans = (int *)malloc(sizeof(int) * (queriesSize + 5));
    *returnSize = queriesSize;
    for (int i = 0; i < queriesSize; i++) {
        ans[i] = sum[queries[i][0]] ^ sum[queries[i][1] + 1];
    }
    return ans;
}