#define MAX_SIZE 10000
bool help(char input) {
    if ((input == 'a') || (input == 'e') || (input == 'i') || (input == 'o') || (input == 'u') ||
    (input == 'A') || (input == 'E') || (input == 'I') || (input == 'O') || (input == 'U')) {
        return true;
    }
    return false;
}

void move(char* p, int size) {
    int i = 0;
    char tmp = p[0];
    while (i < size - 1) {
        p[i] = p[i + 1];
        i++;
    }
    p[size - 1] = tmp;
}

void add(char* p, int* index, int num) {
    while (num > 0) {
        p[(*index)++] = 'a';
        num--;
    }
}
char * toGoatLatin(char * S){
    char* res = (char*)malloc(MAX_SIZE);
    if (res == NULL) return NULL;
    memset(res, 0, MAX_SIZE);
    int index = 0, num = 1;
    char* p = strtok(S, " ");
    while (p != NULL) {
        // 对每一个分隔的单词进行处理，并填到结果中
        int len = strlen(p);
        // 1.判断元音
        if (!help(p[0])) {
            move(p, len); // 辅音处理
        }
        strncpy((res + index), p, len);
        index += len;
        // 2.添加ma
        res[index++] = 'm';
        res[index++] = 'a';
        // 3.添加多个a
        add((res), &index, num);
        
        // 补充空格
        res[index++] = ' ';
        p = strtok(NULL, " ");
        num++;
    }
    if (index > 0) {
        index--;
        res[index] = '\0';
    }
    return res;
}