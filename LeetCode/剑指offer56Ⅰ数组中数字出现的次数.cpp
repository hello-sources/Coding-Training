/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 整体思路就是先用异或运算计算得到两个数的异或和，然后再找出某位的1，用这个把两个数进行区分开来
 * 区分两个数过程中，分别使用两个数接受不同的两个数字，就是对于该位置有相同1的进行异或得到其中一个答案
 * 同时对于另一个位置不是1的数字进行异或得到另一个答案
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize){
    int res = 0, pos = 0, ans1 = 0, ans2 = 0;
    int *ans = (int *)malloc(sizeof(int) * 5);
    for (int i = 0; i < numsSize; i++) res ^= nums[i];
    for (int i = 0; i < 32; i++) {
        if ((res >> i) & 1 == 1) {
            pos = i;
            break;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] >> pos) & 1 == 1) ans1 ^= nums[i];
        else ans2 ^= nums[i];
    }
    ans[0] = ans1, ans[1] = ans2; 
    *returnSize = 2;
    return ans;
}