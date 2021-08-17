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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        ListNode* p1 = l1; 
        ListNode* p2 = l2;
        ListNode* sumHead = new ListNode();
        ListNode* sumCurr = sumHead;
        while(p1 != NULL && p2 != NULL)
        {
            sumCurr->next = new ListNode((p1->val + p2->val + carry) % 10);
            sumCurr = sumCurr->next;

            carry = (p1->val + p2->val + carry) / 10;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        while(p1 != NULL)
        {
            sumCurr->next = new ListNode((p1->val + carry) % 10);
            sumCurr = sumCurr->next;

            carry = (p1->val + carry) / 10;
            p1 = p1->next;
        }
        
        while(p2 != NULL)
        {
            sumCurr->next = new ListNode((p2->val + carry) % 10);
            sumCurr = sumCurr->next;

            carry = (p2->val + carry) / 10;
            p2 = p2->next;
        }
        
        if(carry != 0)
            sumCurr->next = new ListNode(carry);
        
        return sumHead->next;
    }
};