int add(int a, int b){
    int x = a ^ b;
    int y = (a & b) << 1;
    while (y != 0) {
        int temp = x ^ y;
        y = (x & y) << 1;
        x = temp;
    } 
    return x;
}