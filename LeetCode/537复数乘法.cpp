char * complexNumberMultiply(char * num1, char * num2){
    int a, b, c, d, e, f;
    char *res = (char *)malloc(sizeof(char) * 20);
    sscanf(num1, "%d+%di", &a, &b);
    sscanf(num2, "%d+%di", &c, &d);
    e = a * c - b * d;
    f = a * d + b * c;
    sprintf(res, "%d+%di", e, f);
    return res;
}