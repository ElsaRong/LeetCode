/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //集合（内部实现哈哈希表）存储指针，find()判断是否已存在该指针
        if (NULL == head) return false;
        
        unordered_set<ListNode *> pSet;
        pSet.insert(head);
        while (head->next) {
            if (pSet.find(head->next) == pSet.end()) {
                pSet.insert(head->next);
                head = head->next;
            } else {
                return true;;
            }
        }   
        return false;
    }
};
