/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode newHead;
    struct ListNode *now, *pre;

    if (NULL == head)
        return NULL;

    pre = head;
    now = &newHead;

    while (now != head) {
        pre = head;
        if (pre->next == NULL) {  //剩余2个
            now->next = pre;
            return newHead.next;
        }
        while(pre->next->next != NULL) { //剩余3个
            pre = pre->next;
        } 
        now->next = pre->next;
        now = now->next;
        pre->next = NULL;
    }
    return newHead.next;
}
