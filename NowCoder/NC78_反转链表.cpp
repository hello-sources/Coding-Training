/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */

/**
 * 
 * @param pHead ListNode类 
 * @return ListNode类
 */
struct ListNode* ReverseList(struct ListNode* pHead ) {
    // write code here
    struct ListNode *p = NULL;
    struct ListNode *q;
    while (pHead) {
        q = pHead;
        pHead = pHead->next;
        q->next = p;
        p = q;
    }
    return p;
}