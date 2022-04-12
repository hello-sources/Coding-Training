/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* swapNumbers(int* numbers, int numbersSize, int* returnSize){
    numbers[0] ^= numbers[1];
    numbers[1] ^= numbers[0];
    numbers[0] ^= numbers[1];
    *returnSize = numbersSize;
    return numbers;
}