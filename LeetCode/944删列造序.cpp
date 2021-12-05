int minDeletionSize(char ** strs, int strsSize){
    int len = strlen(strs[0]), cnt = 0;
    for (int i = 0; i < len; i++) {
        int flag = 0;
        for (int j = 1; j < strsSize; j++) {
            if (strs[j - 1][i] <= strs[j][i]) continue;
            else {
                flag = 1;
                break;
            }
        }
        if (flag == 1) cnt++;
    }
    return cnt;
}