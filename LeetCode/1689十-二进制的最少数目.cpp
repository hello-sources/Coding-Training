int minPartitions(char * n){
    int max = 0;
    for (int i = 0; i < strlen(n); i++) {
        max = fmax(max, n[i] - '0');
    }
    return max;
}