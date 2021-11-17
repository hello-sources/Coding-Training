/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * 2);
    int start = 0, end = 0;
    for (int i = 0; i < numbersSize - 1; i++) {
        for (int j = i + 1; j < numbersSize; j++) {
            if (target - (numbers[i] + numbers[j])) continue;
            start = i + 1;
            end = j + 1;
            break;
        }
    }
    ans[0] = start, ans[1] = end;
    *returnSize = 2;
    return ans;
}