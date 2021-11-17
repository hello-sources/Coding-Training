/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * 2);
    int start = 0, end = numbersSize - 1;
    while (start < end) {
        if (numbers[start] + numbers[end] < target) start++;
        else if (numbers[start] + numbers[end] > target) end--;
        else break;
    }
    ans[0] = start, ans[1] = end;
    *returnSize = 2;
    return ans;
}