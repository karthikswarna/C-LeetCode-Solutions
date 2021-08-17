/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Linear time and constant space.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // Find length of A.
        ListNode* curr = headA;
        int len1 = 0;
        while(curr != NULL)
        {
            ++len1;
            curr = curr->next;
        }
       
        // Find length of B.
        curr = headB;
        int len2 = 0;
        while(curr != NULL)
        {
            ++len2;
            curr = curr->next;
        }
        
        // Traverse d nodes in the larger list.
        int d = abs(len1 - len2);
        curr = len1 > len2 ? headA : headB;
        while(d > 0)
        {
            --d;
            curr = curr->next;
        }
        
        // Now both the lists can be traversed node-by-node.
        ListNode* curr1 = len1 <= len2 ? headA : headB;
        while(curr != NULL && curr1 != NULL)
        {
            if(curr == curr1) return curr;

            curr = curr->next;
            curr1 = curr1->next;
        }
        
        return NULL;
    }

    // Linear time and space.
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    // {
    //     unordered_set<ListNode*> addr;
    //     ListNode* curr = headB;
    //     while(curr != NULL)
    //     {
    //         addr.insert(curr);
    //         curr = curr->next;
    //     }
        
    //     curr = headA;
    //     while(curr != NULL)
    //     {
    //         if(addr.find(curr) != addr.end())
    //             return curr;

    //         curr = curr->next;
    //     }
        
    //     return NULL;
    // }
};