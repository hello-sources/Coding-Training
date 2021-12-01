//初始化一个空串，然后把word串复制到空串中，使用的是strcat这一拼接函数
//然后使用strstr进行查找sequence中是否存在相关子串
int maxRepeating(char * sequence, char * word){
    int len = strlen(sequence), len2 = strlen(word);
    char *temp = (char *)calloc(len + 50, sizeof(char));
    int cnt = 0, ret = len2;
    while (ret <= len) {
        strcat(temp, word);
        if (strstr(sequence, temp) != NULL) {
            cnt++;
            ret += len2;
        } else {
            break;
        }
    }
    return cnt;
}