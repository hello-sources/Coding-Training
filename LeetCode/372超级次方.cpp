int my_calc(int num, int pow) {
    int ret = 1;
    num %= 1337;
    for (int i = 0; i < pow; i++) {
        ret *= num;
        ret %= 1337;
    }
    return ret;
}

int superPow(int a, int* b, int bSize){
    if (a == 1) return 1;
    int sum = 1;
    for (int i = 0; i < bSize; i++) {
        sum = my_calc(sum, 10);
        sum *= my_calc(a, b[i]);
        sum %= 1337;
    }
    return sum;
}