/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        if(l1 == NULL && l2 != NULL)
            return l2;
        if(l1 != NULL && l2 == NULL)
            return l1;

        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p = new struct ListNode();
        ListNode* head = p;
        
        while(p1 != NULL && p2 != NULL)
        {
            if(p1->val >= p2->val)
            {
                p->next = p2;
                p = p2;
                p2 = p2->next;
                p->next = NULL;
            }
            else if (p1->val < p2->val)
            {
                p->next = p1;
                p = p1;
                p1 = p1->next;
                p->next = NULL;
            }
        }
        
        if(p1 != NULL)
            p->next = p1;

        if(p2 != NULL)
            p->next = p2;
        
        return head->next;
    }
};