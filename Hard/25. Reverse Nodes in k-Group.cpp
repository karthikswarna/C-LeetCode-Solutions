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
        
        int count = 1;
        ListNode* curr = head;
        ListNode* kHead = head;         // Head of current k-group list.
        ListNode* prevKTail = head;     // Tail of previous k-group list.
        ListNode* newListHead = NULL;

        while(curr != NULL)
        {
            if(count == k)
            {
                // Store the next node, as links will be modified in reverse();
                ListNode* nextKHead = curr->next;
                reverse(kHead, curr);

                // curr is the head of reversed list.
                if(newListHead == NULL) newListHead = curr;
                if(prevKTail != NULL) prevKTail->next = curr;

                // kHead is the tail of reversed list.
                prevKTail = kHead;
                kHead->next = nextKHead;
                kHead = nextKHead;

                count = 1;
                curr = nextKHead;
            }
            else
            {
                ++count;
                curr = curr->next;
            }
        }
        
        return newListHead;
    }
    
    void reverse(ListNode* start, ListNode* end)
    {
        ListNode* prev = start;
        ListNode* curr = start->next;
        
        start->next = NULL;
        while(prev != end)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
    }
};