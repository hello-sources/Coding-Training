int reverseBits(int num){
    int max_len = 0, cur = 0, temp = 0;
    for (int i = 0; i < 32; i++, num >>= 1) {
        if (num & 1 == 1) cur++;
        else {
            temp = cur;
            cur = 0;
        }
        max_len = fmax(max_len, temp + cur + 1);
    }
    return max_len == 33 ? 32 : max_len;
}