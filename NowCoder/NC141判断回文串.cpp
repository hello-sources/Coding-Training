/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 * 
 * @param str string字符串 待判断的字符串
 * @return bool布尔型
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
bool judge(char* str ) {
    // write code here
    int len = strlen(str), flag = 1;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] - str[len - i - 1]) flag = 0;
    }
    return flag;
s