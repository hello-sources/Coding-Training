/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int get_digit(long long x) {
    int cnt = 0;
    while (x) {
        x /= 10;
        cnt++;
    }
    return cnt;
}

long long* kthPalindrome(int* queries, int queriesSize, int intLength, int* returnSize){
    long long *res = (long long *)malloc(sizeof(long long) * queriesSize);
    int len = (intLength + 1) / 2 - 1;
    int min = pow(10, len);
    char *leftChar = (char *) malloc(sizeof(char) * 16);
    char *sumChar = (char *) malloc(sizeof(char) * 16);
    *returnSize = 0;
    for (int i = 0; i < queriesSize; i++) {
        int temp = min + queries[i] - 1;
        int temp_len = sprintf(leftChar, "%d", temp);
        if (temp_len > len + 1) {
            res[(*returnSize)++] = -1;
        } else {
            memcpy(sumChar, leftChar, sizeof(char) * temp_len);
            int indexLeft = 0;
            int indexRiht = temp_len-1;
            while(indexLeft <= indexRiht)
            {
                char temp = leftChar[indexLeft];
                leftChar[indexLeft] = leftChar[indexRiht];
                leftChar[indexRiht] = temp;
                indexLeft++;
                indexRiht--;
            }
            if(intLength % 2)
                memcpy(sumChar+temp_len,leftChar + 1,sizeof(char) * (temp_len-1));
            else
                memcpy(sumChar+temp_len, leftChar, sizeof(char) * (temp_len));
            sumChar[intLength] = '\0';
            res[*returnSize] = atol(sumChar);
            *returnSize  = *returnSize  + 1;
        }
    }
    free(sumChar);
    free(leftChar);
    return res;
}