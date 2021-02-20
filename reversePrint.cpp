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
    vector<int> reversePrint(ListNode* head) {
        std::stack<ListNode *> nodes;
        ListNode *pNode = head;   //注意：使用tmp节点遍历head更严谨
        unsigned int listLen = 0, i = 0;
        
        while (pNode) 
        {
            nodes.push(pNode);
            pNode = pNode->next;
            listLen++;
        }
        
        vector<int> ret;
        for (i = 0; i < listLen; i++)
        {
            pNode = nodes.top();
            ret.push_back(pNode->val);
            nodes.pop();
        }

        return ret;
    }
};
