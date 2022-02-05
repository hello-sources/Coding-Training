int findComplement(int num){
    int ans = 0;
    long l = 1;
    while (num) {
        int temp = num % 2;
        num /= 2;
        if (temp == 1) temp = 0;
        else temp = 1;
        temp *= l;
        ans += temp;
        l *= 2;
    }
    return ans;
}

/******************another one*********************/
int findComplement(int num) {
    int tmp;
    int i = 0;
    int result = 0;
    while (num > 0) {
        tmp = (num & 1) == 0 ? 1 : 0;
        result += tmp * pow(2, i);
        i++;
        num >>= 1;
    }
    return result;
}