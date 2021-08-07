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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        int pos = 1;
        ListNode* before = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = NULL;
        while(true)
        {
            if(pos == left)
            {
                before = prev;
                prev = curr;
                curr = curr->next;
            }
            else if(pos > left && pos <= right)
            {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                
                if(pos == right)
                {
                    if(before == NULL)
                    {
                        head->next = curr;    
                        head = prev;
                    }
                    else
                    {
                        temp = before->next;
                        temp->next = curr;       
                        before->next = prev;
                    }
                }
            }
            else if(pos < left)
            {
                prev = curr;
                curr = curr->next;                
            }
            else
                break;

            pos++;
        }
        
        return head;
    }
};