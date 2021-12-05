char * toHex(int num){
    char code[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char *res = (char *)calloc(9, sizeof(char));
    for (int i = 7; i >= 0; --i) {
        res[i] = code[num & 0xF];
        num >>= 4;
    }
    res[8] = '\0';
    while (res[0] == '0' && *(res + 1) != '\0') {
        res = res + 1;
    }
    return res;
}