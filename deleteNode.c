/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *next = NULL;
    next = node->next;
    node->val = next->val;
    node->next = next->next;
}
