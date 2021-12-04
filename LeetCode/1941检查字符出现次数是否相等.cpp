bool areOccurrencesEqual(char * s){
    int arr[128] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        arr[s[i]]++;
    } 
    int i = 0;
    for ( ; i < len - 1; i++) {
        if (arr[s[i]] != arr[s[i + 1]]) break;
    }
    return i == len - 1 ? true : false;
}