int get_digits(int num) {
    int len = 0;
    while (num) {
        num /= 10;
        len++;
    }
    return len;
}

int maximum69Number (int num){
    int max = num;
    int len = get_digits(num); 
    for (int i = 0; i < len; i++) {
        int temp = num;
        if ((temp / (int)pow(10, len - i - 1) % 10) == 9) temp -= 3 * pow(10, len - i - 1);
        else temp += 3 * pow(10, len - i - 1);
        max = fmax(temp, max);
    }  
    return max;
}