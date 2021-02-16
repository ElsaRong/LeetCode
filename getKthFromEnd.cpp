/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* curr = head;
        queue <ListNode*> q;

        while (curr) {
            if(q.size() >= k) {
                q.pop();
            }
            q.push(curr);
            curr = curr->next;
        }
        return q.front();
    }
};
