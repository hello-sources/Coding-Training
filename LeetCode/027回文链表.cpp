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
 * @param head ListNode类 the head
 * @return bool布尔型
 */
#include <stdbool.h>
bool isPail(struct ListNode* head ) {
    // write code here
    int ans[10000005] = {0};
    int cnt = 0;
    while (head) {
        ans[cnt++] = head->val;
        head = head->next;
    }
    for (int i = 0; i <= cnt / 2; i++) {
        if (ans[i] - ans[cnt - i - 1]) return false;
    }
    return true;
}