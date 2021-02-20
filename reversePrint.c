/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverseList(struct ListNode* head, int *listLen) {
     struct ListNode *curr = head;
     struct ListNode *pre = NULL;
     struct ListNode *next = NULL;

      while (curr) 
     {
         next = curr->next;
         curr->next = pre;
         pre = curr;
         curr = next;
         (*listLen)++;
     }
     return pre;
 }

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
    int listLen = 0, i = 0;
    struct ListNode *reverseHead = reverseList(head, &listLen);
    int *ret = (int *)malloc(sizeof(int) * listLen);
    for (i = 0; i < listLen; i++)
    {
        ret[i] = reverseHead->val;
        reverseHead = reverseHead->next;
    }
    *returnSize = listLen;
    return ret;
}
