char * generateTheString(int n){
    char *temp = (char *)malloc(sizeof(char) * 505);
    memset(temp, 'a', n);
    temp[n - 1] = 'a' + (n % 2 == 0);
    temp[n] = '\0';
    return temp;
}