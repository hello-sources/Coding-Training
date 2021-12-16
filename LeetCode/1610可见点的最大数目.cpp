/**
 * 本题是几何问题，包括对于极坐标的使用
 * 另外使用的atan2(Y, X)函数， 计算 y/x 的弧（反）正切，以参数符号确定正确的象限。
 * 由于涉及到角度，可以把极坐标转换为直角坐标
 * 然后把得到的角度，使用qsort进行排序，就转换成维护最长子数组的问题了，使用双数组
 * 只要给定的最大值减去最小值满足符合条件，就行了。
*/

int cmp(const void *a, const void *b) {
    double *aa = (double *)a;
    double *bb = (double *)b;
    return *aa > *bb ? 1 : -1;
}

int visiblePoints(int** points, int pointsSize, int* pointsColSize, int angle, int* location, int locationSize){
    double angles[2 * pointsSize];
    double PI = acos(-1);
    int angleCnt = 0, extraCnt = 0;
    for (int i = 0; i < pointsSize; i++) {
        int deltaX = points[i][0] - location[0];
        int deltaY = points[i][1] - location[1];
        if (deltaX == 0 && deltaY == 0) {
            extraCnt++;
            continue;
        }
        double curAngle = atan2(deltaY, deltaX);
        angles[angleCnt++] = curAngle;
        angles[angleCnt++] = curAngle + 2 * PI;
    }
    qsort(angles, angleCnt, sizeof(double), cmp);
    int left = 0, right = 0, ans = 0;
    double threshold = angle * PI / 180;
    while (1) {
        if (right == angleCnt) {
            return ans + extraCnt;
        }
        if (angles[right] - angles[left] <= threshold) {
            int temp = right - left + 1;
            ans = fmax(ans, temp);
            right++;
        } else {
            left++;
        }
    }
}