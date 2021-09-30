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
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        vector<ListNode* > result;
        
        // Find the length of list.
        int len = 0;
        ListNode* curr = head;
        while(curr != NULL)
        {
            ++len;
            curr = curr->next;
        }

        curr = head;
        while(k)
        {
            // Main step.
            int partLen = ceil((double)len / (double)k);
            --k;

            result.push_back(curr);
            len -= partLen;

            // Goto the last node of the current part.
            while(partLen > 1 && curr != NULL)
            {
                --partLen;
                curr = curr->next;
            }

            // Separate the current part from list.
            if(curr != NULL)
            {
                head = curr->next;
                curr->next = NULL;
                curr = head;
            }
        }

        return result;
    }
};