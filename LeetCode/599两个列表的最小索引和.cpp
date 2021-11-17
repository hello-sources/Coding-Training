/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    int l1 = list1Size - 1, l2 = list2Size - 1;
    char **ans = (char **)malloc(sizeof(char*) * (list1Size + list2Size));
    *returnSize = 0;
    for (int i = 0; i < list1Size; i++) {
        for (int j = 0; j < list2Size; j++) {
            if (strcmp(list1[i], list2[j]) == 0) {
                if (l1 + l2 > i + j) {
                    *returnSize = 0;
                    ans[(*returnSize)++] = list1[i];
                    l1 = i;
                    l2 = j;
                } else if (i + j == l1 + l2) {
                    ans[(*returnSize)++] = list1[i];
                }
            }
        }
    }
    return ans;
}