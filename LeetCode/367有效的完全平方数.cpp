bool isPerfectSquare(int num){
    int temp = sqrt(num);
    if (temp * temp != num) return false;
    return true;
}

/****************不使用库函数--牛逼哄哄的牛顿迭代法*************/
bool isPerfectSquare(int num){
    double x0 = num;
    while (true) {
        double x1 = (x0 + num / x0) / 2;
        if (x0 - x1 < 1e-6) break;
        x0 = x1;
    }
    int x = (int)x0;
    return x * x == num;
}