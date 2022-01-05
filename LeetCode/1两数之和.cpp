/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *a = (int *)malloc(sizeof(int) * 2);
    a[0] = 0;
    a[1] = 0;
	for (int i = 0; i < numsSize - 1; i++) {
		for (int j = i+1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				a[0] = i;
				a[1] = j;
                *returnSize = 2;
				return a;
			}
		}
	}
	return 0;
}