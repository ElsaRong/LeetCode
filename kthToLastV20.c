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
    //快指针比慢指针领先k步
    while (kthToHeadNode) 
    {
        kthToLastNode = kthToLastNode->next;
        kthToHeadNode = kthToHeadNode->next;
    }
    return kthToLastNode->val;
}
