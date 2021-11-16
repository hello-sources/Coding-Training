/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param pHead ListNode类 
 * @param k int整型 
 * @return ListNode类
 */
struct ListNode* FindKthToTail(struct ListNode* pHead, int k ) {
    // write code here
    struct ListNode *p = pHead, *q = pHead;
    int cnt = 0;
    while (p) {
        cnt++;
        p = p->next;
    }
    if (cnt < k) return NULL;
    p = pHead;
    for (int i = 0; i < k; i++) q = q->next;
    while (q) {
        q = q->next;
        p = p->next;
    }
    return p;
}