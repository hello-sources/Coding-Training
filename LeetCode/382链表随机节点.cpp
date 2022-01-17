/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct {
    int *node;
    int size;
} Solution;

Solution* solutionCreate(struct ListNode* head) {
    Solution *obj = (Solution *)malloc(sizeof(Solution));
    struct ListNode *temp = head;
    int cnt = 0;
    obj->size = 0;
    while (temp) {
        cnt++;
        temp = temp->next;
    }
    obj->node = (int *)malloc(sizeof(int) * (cnt + 5));
    memset(obj->node, 0, sizeof(obj->node));
    temp = head;
    while (temp) {
        obj->node[obj->size++] = temp->val;
        temp = temp->next;
    }
    return obj;
}

int solutionGetRandom(Solution* obj) {
    return obj->node[rand() % obj->size];
}

void solutionFree(Solution* obj) {
    if (obj == NULL) return ;
    free(obj->node);
    free(obj);
    return ;
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/