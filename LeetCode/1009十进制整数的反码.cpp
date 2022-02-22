int bitwiseComplement(int n){
    if (n == 0) return 1;
    int cnt = 0, temp = n, num = 0;
    while (temp) {
        temp >>= 1;
        cnt++;
    }
    for (int i = 0; i < cnt; i++) {
        num = (num << 1) + 1;
    }
    return (~n & num);
}