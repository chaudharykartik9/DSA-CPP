class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            decltype([](ListNode* a, ListNode* b) {
                return a->val > b->val;
            })
        > pq;

        for (auto node : lists) {
            if (node != NULL) {
                pq.push(node);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (!pq.empty()) {

            ListNode* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != NULL) {
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }
};