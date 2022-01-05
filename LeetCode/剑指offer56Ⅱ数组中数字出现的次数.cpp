/**
 * 整体思路就是把每一个数字转换为二进制数，并且把对应位置的1都记录下来，
 * 存储到一个一维的数组中去，再对结果中每一位取模3，对应位置得到的结果如果是1
 * 表示答案的那一位存在1，可以初始化一个值为0的点，每次左移1位，然后再与对应数组中的值异或
 * **/
int singleNumber(int* nums, int numsSize){
    int num[32] = {0}, ans = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < 32; j++) {
            num[j] += (nums[i] & 1);
            nums[i] >>= 1;
        }
    }
    for (int i = 0; i < 32; i++) {
        ans <<= 1;
        ans |= num[31 - i] % 3;
    }
    return ans;
}