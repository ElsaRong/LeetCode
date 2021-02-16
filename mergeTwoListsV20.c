/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode preHead; //头节点，用于记录新的链表路径首节点，不动
    struct ListNode *pre = NULL;    //遍历指针，服务于preHead的next
    pre = &preHead;

    //注意：空指针校验
    if (NULL == l1 && NULL == l2) {
        return pre;
    }

    while (NULL != l1 && NULL != l2) {
        if (l1->val < l2->val) {
            pre->next = l1;
            l1 = l1->next;
        } else {
            pre->next = l2;
            l2 = l2->next;
        } 
        pre = pre->next;
    }

    if (NULL == l1 && NULL != l2) {
        pre->next = l2;
    }
    if (NULL == l2 && NULL != l1) {
        pre->next = l1;
    }
   return preHead.next;
}
