/***
 * 其实这是个数学题，通过给定的字符串s，构造出来的最长回文字符串，长度肯定小于等于s，如果小于s，那么最长回文串b的长度必然是奇数。
因此要先数出给定字符串中各个字符的数量，这是第一个for循环完成的工作。
然后是把字符出现数量加起来，偶数次数的直接加，奇数次数的减一后再加。
最后返回结果的时候判断下，回文串的长度是不是和s相同，不同的话就再加1。
 * ***/

int longestPalindrome(char * s){
    int len = strlen(s), cnt = 0;
    if (len <= 1) return len;
    int arr[128] = {0};
    for (int i = 0; i < len; i++) {
        arr[s[i]]++;
    }
    for (int i = 0; i < 128; i++) {
        cnt += arr[i] - arr[i] % 2;
    }
    return cnt + (cnt != len);
}