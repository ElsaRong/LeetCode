/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode* head) {
    struct ListNode *curr = head;
    struct ListNode *pre = NULL;
    struct ListNode *next = NULL;

    while (curr) 
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}

int kthToLast(struct ListNode* head, int k){
    struct ListNode *reverseHead = reverseList(head);
    while (k > 1) {
        reverseHead = reverseHead->next;
        k--;
    }
    return reverseHead->val;
}
