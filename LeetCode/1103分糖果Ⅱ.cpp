/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* distributeCandies(int candies, int num_people, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * num_people);
    memset(res, 0, sizeof(int) * num_people);
    *returnSize = num_people;
    int i = 0;
    while (candies > 0) {
        res[(i % num_people)] += fmin(candies, i + 1);
        candies -= fmin(candies, i + 1);
        i++;
    }
    return res;
}