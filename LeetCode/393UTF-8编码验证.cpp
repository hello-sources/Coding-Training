int GetNumByte(int num) {
    int checknum = num & 0xFF;
    // 0*** ****
    if ((checknum >> 7) == 0) {
        return 1;
    }

    // 110** ****  -> 0110
    if ((checknum >> 5) == 6) {
        return 2;
    }
    
    // 1110 ****  -> 1110
    if ((checknum >> 4) == 14) {
        return 3;
    }
    
    // 1111 **** -> 1 1110
    if ((checknum >> 3) == 30) {
        return 4;
    }
    return -1;
}


bool CheckAfterByte(int num) {
    int checknum = num & 0xFF;
    if ((checknum >> 6) == 2) {
        return true;
    }
    return false;
}

bool validUtf8(int* data, int dataSize){
    for (int i = 0; i < dataSize; ) {
        int bytes = GetNumByte(data[i]);
        if (bytes == -1) {
            return false;
        }
        if (bytes > dataSize - i) {
            return false;
        }
        
        int nextpos = i + 1;
        for (int j = i + 1; j < i + bytes ; j++) {
            if (!CheckAfterByte(data[j])) {
                return false;
            }
            nextpos = j + 1;
        }
         i = nextpos;
    }
    return true;
}