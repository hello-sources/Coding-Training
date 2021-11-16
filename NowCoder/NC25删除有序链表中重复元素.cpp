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
 * @param head ListNode类 
 * @return ListNode类
 */
struct ListNode* deleteDuplicates(struct ListNode* head ) {
    // write code here
    struct ListNode *p = head;
    if (p == NULL) return NULL;
    while (p && p->next) {
        if (p->val == p->next->val) p->next = p->next->next;
        else p = p->next;
    }
    return head;
}