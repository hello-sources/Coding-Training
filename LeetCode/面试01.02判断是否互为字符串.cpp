bool CheckPermutation(char* s1, char* s2){
    int num1[128] = {0};
    int num2[128] = {0};
    for (int i = 0; s1[i]; i++) {
        num1[s1[i]]++;
    }
    for (int i = 0; s2[i]; i++) {
        num2[s2[i]]++;
    }
    int flag = 0;
    for (int i = 0; i < 128; i++) {
        if (num1[i] != num2[i]) {
            flag = 1;
            break;
        }
    }
    return flag == 0;
}