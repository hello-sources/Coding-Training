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
 * @param head ListNode类 the head node
 * @return ListNode类
 */
void quick_sort(int *nums, int left, int right){
    if (left > right) return;
    int i = left, j = right, temp = nums[left];
    while (i < j){
        while (i < j && temp <= nums[j])
            j--;
        if (i < j)
            nums[i++] = nums[j];
        while (i < j && temp > nums[i])
            i++;
        nums[j--] = nums[i];
    }
    nums[i] = temp;
    quick_sort(nums, left, i - 1);
    quick_sort(nums, i + 1, right);
}

struct ListNode* sortInList(struct ListNode* head ) {
    // write code here
    struct ListNode *p = head;
    int cnt = 0, res = 0, index = 0;
    while (p) {
        cnt++;
        p = p->next;
    }
    int *ans = (int *)malloc(sizeof(int) * cnt);
    p = head;
    while (p) {
        ans[index++] = p->val;
        p = p->next;
    }
    quick_sort(ans, 0, cnt - 1);
    p = head;
    while (p) {
        p->val = ans[res++];
        p = p->next;
    }
    return head;
}


/*---------------------冒泡排序--------------------------*/
struct ListNode* sortInList(struct ListNode* head ) {
    // write code here
    struct ListNode *p = head;
    int *ans = (int *)malloc(sizeof(int) * 100005);
    int cnt = 0, index = 0;
    while (p) {
        ans[cnt++] = p->val;
        p = p->next;
    }
    for (int i = 0; i < cnt - 1; i++) {
        for (int j = 0; j < cnt - i - 1; j++) {
            if (ans[j] > ans[j + 1]) {
                int temp = ans[j];
                ans[j] = ans[j + 1];
                ans[j + 1] = temp;
            }
        }
    }
    p = head;
    while (p) {
        p->val = ans[index++];
        p = p->next;
    }
    return head;
}