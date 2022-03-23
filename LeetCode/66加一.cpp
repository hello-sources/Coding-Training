/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
    }
    *returnSize = digitsSize + 1;
    digits = (int *)realloc(digits, sizeof(int) * (*returnSize));
    digits[digitsSize] = 0;
    digits[0] = 1;
    return digits;
}