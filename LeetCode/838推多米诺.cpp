char * pushDominoes(char * dominoes){
    int len = strlen(dominoes), i = 0;
    char left = 'L';
    while (i < len) {
        int j = i;
        while (j < len && dominoes[j] == '.') j++;
        char right = j < len ? dominoes[j] : 'R';
        if (left == right) {
            while (i < j) {
                dominoes[i++] = right;
            }
        } else if (left == 'R' && right == 'L') {
            int k = j - 1;
            while (i < k) {
                dominoes[i++] = 'R';
                dominoes[k--] = 'L';
            }
        }
        left = right;
        i = j + 1;
    }
    return dominoes;
}