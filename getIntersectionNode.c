/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

unsigned int getListLen(struct ListNode *head) {
    unsigned int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *longList = headA;   //注意：《剑指Offer》示例命名pListHeadLong,pListHeadShort
    struct ListNode *shortList = headB;
    unsigned int listLenA = 0;           //注意：《剑指Offer》示例命名nLength1,nLength2
    unsigned int listLenB = 0;
    unsigned int diffVal = 0;
    int i = 0;

    listLenA = getListLen(headA);
    listLenB = getListLen(headB);
    diffVal = listLenA - listLenB;
    if(listLenA < listLenB) 
    {
        longList = headB;
        shortList = headA;
        diffVal = listLenB - listLenA;
    }

    for(i = 0; i < diffVal; i++) 
    {
        longList = longList->next; 
        if (!longList)
            return NULL;
    }
               

    while((longList != NULL) && (shortList != NULL) && (longList != shortList)) 
    {
        longList = longList->next;
        shortList = shortList->next;
    }

    struct ListNode *pFirstCommonNode = longList;
    return pFirstCommonNode;
}
