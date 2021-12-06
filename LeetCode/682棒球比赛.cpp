int calPoints(char ** ops, int opsSize){
    int num[1003] = {0}, cnt = 0,sum = 0;
    for (int i = 0; i < opsSize; i++) {
        if (strcmp(ops[i], "D") == 0) {
            num[cnt] = num[cnt - 1] * 2;
            cnt++;
        } else if (strcmp(ops[i], "C") == 0) {
            num[cnt - 1] = 0;
            cnt--;
        } else if (strcmp(ops[i], "+") == 0) {
            num[cnt] = num[cnt - 1] + num[cnt - 2];
            cnt++;
        } else {
            if (ops[i][0] == '-') {
                int temp;
                sscanf(ops[i], "-%d", &temp);
                num[cnt++] = -temp;
            } else {
                int temp;
                sscanf(ops[i], "%d", &temp);
                num[cnt++] = temp;
            }
        }
    }
    for (int i = 0; i < cnt; i++) {
        sum += num[i];
    }
    return sum;
}