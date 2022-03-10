int bestRotation(int* nums, int numsSize){
    int * diffs = (int *)malloc(sizeof(int) * numsSize);
    memset(diffs, 0, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        int low = (i + 1) % numsSize;
        int high = (i - nums[i] + numsSize + 1) % numsSize;
        diffs[low]++;
        diffs[high]--;
        if (low >= high) {
            diffs[0]++;
        }
    }
    int bestIndex = 0, maxScore = 0, score = 0;
    for (int i = 0; i < numsSize; i++) {
        score += diffs[i];
        if (score > maxScore) {
            bestIndex = i;
            maxScore = score;
        }
    }
    free(diffs);
    return bestIndex;
}