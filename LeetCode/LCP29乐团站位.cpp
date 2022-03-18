/* 先算第几层, 然后计算在当前层的哪个边 */
int orchestraLayout(int num, int xPos, int yPos){
    int m = fmin(fmin(xPos, num - 1 - xPos), fmin(yPos, num - 1 - yPos));
    long cur = num;
    long sum = (4 * cur - 4 * m) * m; /* 等差数列求和 */
    cur -= m * 2;  /* 当前层的长度 */
    sum %= 9;
    
    /* 当前层的4个顶点坐标为[m, m], [m, num-m-1], [num-m-1,num-m-1], [num-m-1,m] */
    if (m == xPos) {   /* 上 */
        sum += yPos - m + 1;
    } else if (m == num - 1 - yPos) {  /* 右 */
        sum += cur - 1;
        sum += xPos - m + 1;
    } else if (m == num - 1 - xPos) {  /* 下 */
        sum += 2 * cur - 2;
        sum += num - m - 1 - yPos + 1;
    } else {  /* 左 */
        sum += 3 * cur - 3;
        sum += num - m - 1 - xPos + 1;
    }
    sum %= 9;
    return sum == 0 ? 9 : sum;
}