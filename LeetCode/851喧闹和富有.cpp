/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct LinkNode {
    int val;
    struct LinkNode *next;
} LinkNode;

void insert(LinkNode *head, int val) {
    LinkNode *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = (LinkNode *)malloc(sizeof(LinkNode));
    temp->next->val = val;
    temp->next->next = NULL;
    return ;
}

void getAns(int *ans, LinkNode *rich, int *quiet, int i) {
    if (ans[i] != -1) return ;
    else {
        LinkNode *temp = &rich[i];
        int min = i;
        while (temp->next) {
            temp = temp->next;
            getAns(ans, rich, quiet, temp->val);
            min = quiet[min] < quiet[ans[temp->val]] ? min : ans[temp->val];
        }
        ans[i] = min;
    }
    return ;
}

int* loudAndRich(int** richer, int richerSize, int* richerColSize, int* quiet, int quietSize, int* returnSize){
    LinkNode *rich = (LinkNode *)malloc(sizeof(LinkNode) * quietSize);
    for (int i = 0; i < quietSize; i++) {
        rich[i].val = -1;
        rich[i].next = NULL;
    }
    for (int i = 0; i < richerSize; i++) {
        insert(&rich[richer[i][1]], richer[i][0]);
    }
    int *ans = (int *)malloc(sizeof(int) * quietSize);
    for (int i = 0; i < quietSize; i++) {
        ans[i] = -1;
    }
    for (int i = 0; i < quietSize; i++) {
        getAns(ans, rich, quiet, i);
    }
    *returnSize = quietSize;
    free(rich);
    return ans;
}