/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head){
    int a[100000] = {0};  //注意：很烂的代码，默认申请10w字节
    int i = 0, j = 0;

    if (NULL == head || NULL == head->next) //注意：判NULL的先后顺序是从左至右，否则head->next为空导致崩溃
        return true;

    while(NULL != head) {
        a[i++] = head->val;
        head = head->next;
    }
    j = i - 1;
    for (i = 0; i <= j; i++, j--) {
        if (a[i] != a[j])
            return false;
    }
    return true;
}
