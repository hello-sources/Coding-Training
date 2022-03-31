int convertInteger(int A, int B){
    int temp = A ^ B, cnt = 0;
    for (int i = 0; i < 32; i++) {
        if ((temp >> i) & 1 == 1) cnt++;
    }
    return cnt;
}
