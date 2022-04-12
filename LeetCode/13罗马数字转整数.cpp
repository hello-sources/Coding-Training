int getVal(char c) {
    switch (c) {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
    }
    return 0;
}

int romanToInt(char * s){
    int num = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i + 1] == 0 || getVal(s[i]) >= getVal(s[i + 1])) {
            num += getVal(s[i]);
        } else {
            num -= getVal(s[i]);
        }
    }
    return num;
}