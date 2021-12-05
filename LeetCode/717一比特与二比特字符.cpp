bool isOneBitCharacter(int* bits, int bitsSize){
    int i = 0;
    while (i < bitsSize - 1) {
        if (bits[i] == 1) {
            i += 2;
        } else i++;
    }
    if (i < bitsSize) return true;
    return false;
}