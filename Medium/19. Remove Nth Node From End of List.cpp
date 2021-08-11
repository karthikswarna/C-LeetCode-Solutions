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
    // Two passes. 1) Find the length of list. 2) Delete the node.
    // ListNode* removeNthFromEnd(ListNode* head, int n)
    // {
    //     int len = 0;
    //     ListNode* curr = head;
    //     while(curr != NULL)
    //     {
    //         ++len;
    //         curr = curr->next;
    //     }
        
    //     if(len == n) return head->next;
        
    //     n = len - n + 1;
    //     curr = head;
    //     ListNode* prev = NULL;
    //     while(n > 1)
    //     {
    //         --n;
    //         prev = curr;
    //         curr = curr->next;
    //     }
        
    //     prev->next = curr->next;
    //     return head;
    // }

    // One pass - Maintain two pointers which move such that by the time second pointer reaches the end of list, the first pointer is at the Nth node from end.
    // i.e First pointer moves once every n times second pointer moves.
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* fast = head;
        ListNode* slow = NULL;
        ListNode* prev_slow = NULL;
        int i = 0;
        while(fast != NULL)
        {
            ++i;
            
            fast = fast->next;
            
            if(i >= n)
            {
                prev_slow = slow;
                slow = slow == NULL ? head : slow->next;
            }
        }

        if(slow == head) return head->next;
        
        prev_slow->next = slow->next;
        
        return head;
    }
};