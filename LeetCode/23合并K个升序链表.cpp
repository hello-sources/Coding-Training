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
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> prq;
        for (auto node : lists) {
            if (node) prq.push(node);
        }
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (!prq.empty()) {
            ListNode *t = prq.top();
            prq.pop();
            cur->next = t;
            cur = t;
            if (t->next) {
                prq.push(t->next);
            }
        }
        return dummy->next;
    }
};