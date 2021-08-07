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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(k == 1) return head;

        ListNode* curr = head;
        ListNode* prevEnd = NULL;
        ListNode* khead = head;
        ListNode* newListHead = head;

        int count = 1;
        bool firstReversal = true;
        while(curr != NULL)
        {
            curr = curr->next;
            
            if(curr != NULL)
                count++;
            else
                break;
            
            if(count == k)
            {
                ListNode* temp = curr->next;

                // Link the reversed list with preceding part of full list.
                if(firstReversal)
                {
                    // Remember the first part's head to return.
                    newListHead = reverseList(khead, curr);
                    firstReversal = false;
                }
                else
                    prevEnd->next = reverseList(khead, curr);

                
                // Link the reversed list with succeeding part of full list.
                prevEnd = khead;
                khead->next = temp;
                
                // Reset variables for next k-length part.
                khead = temp;
                curr = temp;
                count = 1;
            }
        }
        
        return newListHead;
    }
    
    // Reverses the list from start node to end node (both inclusive). Returns the head.
    ListNode* reverseList(ListNode* start, ListNode* end)
    {
        ListNode* prev = start;
        ListNode* curr = start->next;
        ListNode* temp;

        while(true)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            
            if(prev == end)
                break;
        }
        
        return end;
    }
};