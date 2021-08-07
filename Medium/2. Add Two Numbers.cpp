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
        ListNode* sum = NULL;
        ListNode* curSum = sum;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while(cur1 != NULL && cur2 != NULL)
        {
            if(sum == NULL)
            {
                curSum = new ListNode();
                sum = curSum;
            }
            else
            {
                curSum->next = new ListNode();
                curSum = curSum->next;
            }
            curSum->val = (cur1->val + cur2->val + carry) % 10;

            carry = (cur1->val + cur2->val + carry) / 10;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        if(cur1 == NULL && cur2 != NULL)
        {
            while(cur2 != NULL)
            {
                curSum->next = new ListNode();
                curSum = curSum->next;
                curSum->val = (cur2->val + carry) % 10;

                carry = (cur2->val + carry) / 10;
                cur2 = cur2->next;
            }
        }
        
        if(cur1 != NULL && cur2 == NULL)
        {
            while(cur1 != NULL)
            {
                curSum->next = new ListNode();
                curSum = curSum->next;
                curSum->val = (cur1->val + carry) % 10;

                carry = (cur1->val + carry) / 10;
                cur1 = cur1->next;
            }
        }
        
        if(carry != 0)
        {
            curSum->next = new ListNode();
            curSum = curSum->next;
            curSum->val = carry;
        }

        return sum;
    }
};