char ** split(const char * s, char delim, int * returnSize) {
    int n = strlen(s);
    char ** ans = (char **)malloc(sizeof(char *) * n);
    int pos = 0;
    int curr = 0;
    int len = 0;
    
    while (pos < n) {
        while (pos < n && s[pos] == delim) {
            ++pos;
        }
        curr = pos;
        while (pos < n && s[pos] != delim) {
            ++pos;
        }
        if (curr < n) {
            ans[len] = (char *)malloc(sizeof(char) * (pos - curr + 1)); 
            strncpy(ans[len], s + curr, pos - curr);
            ans[len][pos - curr] = '\0';
            ++len;
        }
    }
    *returnSize = len;
    return ans;
}

char * simplifyPath(char * path){
    int namesSize = 0;
    int n = strlen(path);
    char ** names = split(path, '/', &namesSize);
    char ** stack = (char **)malloc(sizeof(char *) * namesSize);
    int stackSize = 0;
    for (int i = 0; i < namesSize; ++i) {
        if (!strcmp(names[i], "..")) {
            if (stackSize > 0) {
                --stackSize;
            } 
        } else if (strcmp(names[i], ".")){
            stack[stackSize] = names[i];
            ++stackSize;
        } 
    }
    
    char * ans = (char *)malloc(sizeof(char) * (n + 1));
    int curr = 0;
    if (stackSize == 0) {
        ans[curr] = '/';
        ++curr;
    } else {
        for (int i = 0; i < stackSize; ++i) {
            ans[curr] = '/';
            ++curr;
            strcpy(ans + curr, stack[i]);
            curr += strlen(stack[i]);
        }
    }
    ans[curr] = '\0';
    for (int i = 0; i < namesSize; ++i) {
        free(names[i]);
    }
    free(names);
    free(stack);
    return ans;
}


/**********************strtok()走天下**************************/
char * simplifyPath(char * path){
    char *stack[100];
    int size = 0;
    for(char *s = strtok(path, "/"); s; s = strtok(NULL, "/")){
        if (strcmp(s, ".") == 0){    //do nothing
        }else if(strcmp(s, "..") == 0){      //back 
            size = fmax(0, size-1);
        }else{
            stack[size++] = s;
        }
    }
    if (size == 0) 
        return "/";
    char *res = calloc(1000, sizeof(char));
    for (int i = 0;i < size; ++i) {
        strcat(res, "/");
        strcat(res, stack[i]);
    }
    return res;
}