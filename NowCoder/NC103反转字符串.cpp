/**
 * 反转字符串
 * @param str string字符串 
 * @return string字符串
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
char* solve(char* str ) {
    // write code here
    int len = strlen(str);
    int i = 0;
    char *ans = (char *)malloc(sizeof(char)* len);
    while (i < len) {
        ans[i] = str[len - i - 1];
        i++;
    }
    return ans;
}

//双指针法
char* solve(char* str ) {
    // write code here
    int len = strlen(str);
    int i = 0;
    char *ans = (char *)malloc(sizeof(char)* len);
    while (i < len) {
        ans[i] = str[len - i - 1];
        i++;
    }
    return ans;
}