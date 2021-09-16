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
class Solution
{
public:
    // Merge Sort. Time: O(N*log(N)), Space: O(1)
    ListNode* sortList(ListNode* head)
    {
        // Base Case.
        if(head == NULL || head->next == NULL) return head;

        ListNode* mid = getMidPoint(head);
        ListNode* firstHalf = sortList(head);
        ListNode* secondHalf = sortList(mid);
        
        return merge(firstHalf, secondHalf);
    }
    
    // Merges two linked lists into one and returns its head. 
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        ListNode* head = new ListNode(0);
        ListNode* curr = head;

        while(p1 != NULL && p2 != NULL)
        {
            if(p1->val < p2->val)
            {
                curr->next = p1;
                curr = curr->next;
                p1 = p1->next;
                curr->next = NULL;
            }
            else
            {
                curr->next = p2;
                curr = curr->next;
                p2 = p2->next;
                curr->next = NULL;
            }
        }
        
        if(p1 != NULL) curr->next = p1;
        else if(p2 != NULL) curr->next = p2;
        
        return head->next;
    }
    
    // Splits the list into half and returns the head of second part.
    ListNode* getMidPoint(ListNode* start)
    {
        if(start->next == NULL) return start;

        ListNode* fast = start;
        ListNode* slow = start;
        ListNode* prevSlow = NULL;

        while(fast != NULL)
        {
            fast = (fast->next == NULL) ? NULL : fast->next->next;
            prevSlow = slow;
            slow = slow->next;
        }

        prevSlow->next = NULL;

        return slow;
    }
};