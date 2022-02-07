int exchangeBits(int num){
    int a = 0B10101010101010101010101010101010;
    int b = 0B01010101010101010101010101010101;
    a &= num, b &= num;
    a >>= 1;
    b <<= 1;
    return a | b;
}