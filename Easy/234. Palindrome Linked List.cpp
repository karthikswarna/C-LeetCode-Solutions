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
    // Time: O(N) Space: O(N)
    bool isPalindrome(ListNode* head)
    {
        vector<int> V;
        while(head != NULL)
        {
            V.push_back(head->val);
            head = head->next;
        }
        
        int i = 0;
        int j = V.size() - 1;
        while(i < j)
        {
            if(V[i] != V[j])
                return false;

            ++i;
            --j;
        }
        
        return true;
    }

    // Time: O(N) Space: O(1)
//     bool isPalindrome(ListNode* head)
//     {
//         // Find length of list.
//         int len = 0;
//         ListNode* curr = head;
//         while(curr != NULL)
//         {
//             curr = curr->next;
//             ++len;
//         }
        
//         // Find the second half.
//         curr = head;
//         int i = 0;
//         while(i < len/2)
//         {
//             curr = curr->next;
//             ++i;
//         }
        
//         // Reverse the second half.
//         ListNode* prev = curr;
//         curr = curr->next;
//         prev->next = NULL;
//         while(curr != NULL)
//         {
//             swap(curr->next, prev);
//             swap(prev, curr);
//         }
        
//         // Comparing the first half and second half. 'prev' has the head of second half.
//         i = 0;
//         while(i < len/2)
//         {
//             if(prev->val != head->val) return false;

//             head = head->next;
//             prev = prev->next;
            
//             ++i;
//         }
        
//         return true;
//     }
};