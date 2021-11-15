#include <stdbool.h>
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
 * @param head ListNode类 
 * @return bool布尔型
 */
bool hasCycle(struct ListNode* head ) {
    // write code here
    if (head == NULL || head->next == NULL) return false;
    struct ListNode *fast = head->next, *slow = head;
    while (fast != slow) {
        if (fast == NULL || fast->next == NULL) return false;
        fast = fast->next->next;
        slow = slow->next;
    }
    return true;
}