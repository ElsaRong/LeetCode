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

    if (NULL == head || NULL == head->next)  //注意：空指针，或只有一个结点的链表
        return head;

    while (curr) {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;        //注意：反转链表后返回的链表首结点不是pre->next
}

struct ListNode *secondHalfStart(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool isPalindrome(struct ListNode* head){
    bool ret = false;
    struct ListNode *divider = NULL;
    struct ListNode *p = head;
    struct ListNode *q = NULL;

    if (NULL == head || NULL == head->next) return true;
    
    //1.快慢指针，找到上半部分最后一个结点
    divider = secondHalfStart(head);

    //2.链表反转，从后半部分第一个结点开始
    q = reverseList(divider->next);

    //3.比较前后两部分
    while (q && p) {               //注意：前后两部分各有且仅有一个结点的情况
        if (q->val != p->val) {
            ret = false;
            break;
        }
        ret = true; 
        p = p->next;
        q = q->next;
    }

    //4.反转链表恢复
    divider->next = reverseList(divider->next);
    return ret;
}
