/*******************动态规划空间为O(n)************************/
int trap(int* height, int heightSize){
    if (heightSize == 0) return 0;
    int left[heightSize], right[heightSize], ans = 0;
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    left[0] = height[0], right[heightSize - 1] = height[heightSize - 1];
    for (int i = 1; i < heightSize; i++) {
        left[i] = fmax(height[i], left[i - 1]);
    }
    for (int i = heightSize - 2; i >= 0; i--) {
        right[i] = fmax(height[i], right[i + 1]);
    }
    for (int i = 0; i < heightSize; i++) {
        ans += fmin(left[i], right[i]) - height[i];
    }
    return ans;
}

/******************双指针优化空间为O(1)***********************/
int trap(int* height, int heightSize){
    int left = 0, right = heightSize - 1;
    int lMax = 0, rMax = 0, ans = 0;
    while (left < right) {
        lMax = fmax(lMax, height[left]);
        rMax = fmax(rMax, height[right]);
        if (lMax < rMax) {
            ans += lMax - height[left];
            left++;
        } else {
            ans += rMax - height[right];
            right--;
        }
    }
    return ans;
}