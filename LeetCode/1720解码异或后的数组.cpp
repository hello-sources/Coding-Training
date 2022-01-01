/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * (encodedSize + 5));
    *returnSize = 0;
    res[(*returnSize)++] = first;
    for (int i = 0; i < encodedSize; i++) {
        res[(*returnSize)++] = encoded[i] ^ first;
        first = res[i + 1];
    }
    return res;
}