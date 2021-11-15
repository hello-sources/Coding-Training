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
 * @return ListNode类
 */
struct ListNode* EntryNodeOfLoop(struct ListNode* pHead ) {
    // write code here
    struct ListNode *fast = pHead;
    struct ListNode *slow = pHead;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) break;
    }
    if (fast == NULL || fast->next == NULL) return NULL;
    slow = pHead;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}