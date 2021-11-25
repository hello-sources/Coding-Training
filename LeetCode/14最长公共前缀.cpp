//纵向比较字符数组
char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0]; 
    int hash[26] = {0};
    for (int i = 0; i < strlen(strs[0]); i++) {
        for (int j = 0; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
}