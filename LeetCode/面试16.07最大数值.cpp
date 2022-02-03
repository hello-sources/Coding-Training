int maximum(int a, int b){
    long c = a, d = b;
    int res = (fabs(c - d) + c + d) / 2;
    return res;
}