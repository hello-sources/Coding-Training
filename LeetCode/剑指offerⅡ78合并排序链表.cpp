/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp{
        bool operator()(ListNode *list1, ListNode *list2) {
            return list1->val > list2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> prq;
        for (auto node : lists){
            if (node) prq.push(node);
        }
        ListNode *res = new ListNode(0);
        ListNode *cur = res;
        while (!prq.empty()) {
            ListNode *t = prq.top();
            prq.pop();
            cur->next = t;
            cur = t;
            if (t->next) {
                prq.push(t->next);
            }
        }
        return res->next;
    }
};