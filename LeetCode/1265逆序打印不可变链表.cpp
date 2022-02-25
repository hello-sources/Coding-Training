/**
 * Definition for ImmutableListNode.
 * struct ImmutableListNode {
 *     struct ImmutableListNode* (*getNext)(struct ImmutableListNode*); // return the next node.
 *     void (*printValue)(struct ImmutableListNode*); // print the value of the node.
 * };
 */
#define MAX_N 1001
void printLinkedListInReverse(struct ImmutableListNode* head) {
    if (head == NULL) return ;
    struct ImmutableListNode *cnt[MAX_N] = {0};
    struct ImmutableListNode *temp = head;
    int num = 0;
    while (temp) {
        cnt[num++] = temp;
        temp = temp->getNext(temp);
    }
    for (int i = num; i > 0; i--) {
        temp = cnt[i-  1];
        temp->printValue(temp);
    }
    return ;
}