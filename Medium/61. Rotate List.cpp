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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == NULL || k == 0) return head;

        int len = 1;
        ListNode* tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
            ++len;
        }

        // Effectively there will be no rotations if k % len == 0
        if(k % len == 0)
            return head;

        // Make the list circular.
        tail->next = head;

        // 0-indexed id for the new tail after k rotations.
        int newTailNodeId = (len - (k % len)) - 1;

// Find the new tail, and make the next node null. Return the tail's next node as head. 
        len = 0;
        tail = head;
        while(len < newTailNodeId)
        {
            tail = tail->next;
            ++len;
        }
        
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};