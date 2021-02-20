/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int kthToLast(struct ListNode* head, int k){
    struct ListNode *kthToHeadNode = head;
    struct ListNode *kthToLastNode = head;
    while (k--) 
    {
        kthToHeadNode = kthToHeadNode->next;
    }
    while (kthToHeadNode) 
    {
        kthToLastNode = kthToLastNode->next;
        kthToHeadNode = kthToHeadNode->next;
    }
    return kthToLastNode->val;
}
