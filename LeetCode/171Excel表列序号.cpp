// int titleToNumber(char * columnTitle){
//     int cnt = strlen(columnTitle);
//     int res = 0;
//     for (int i; columnTitle[i]; i++) {
//         res += (columnTitle[i] - 'A' + 1) * pow(26, cnt - i - 1);
//     }
//     return res;
// }

int titleToNumber(char * columnTitle){
    int j = 0;
    for (int i = 0; columnTitle[i]; i++) {
        j *= 26;
        j += columnTitle[i] - 'A' + 1;
    }
    return j;
}