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
    ListNode* insertionSortList(ListNode* head)
    {
        if(head->next == NULL) return head;

        ListNode* sortedHead = new ListNode(0, head);
        ListNode* curr = head->next;
        head->next = NULL;

        while(curr != NULL)
        {
            ListNode* next = curr->next;
            
            ListNode* temp = sortedHead->next;
            ListNode* prev = sortedHead;
            while(temp != NULL)
            {
                if(temp->val >= curr->val)
                    break;

                prev = temp;
                temp = temp->next;
            }
            prev->next = curr;
            curr->next = temp;

            curr = next;
        }
        
        return sortedHead->next;
    }
};