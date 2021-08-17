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
    ListNode* oddEvenList(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* evenHead = NULL;
        ListNode* curr = head;
        ListNode* prevOdd = NULL;
        ListNode* prevEven = NULL;

        bool isOdd = true;
        while(curr != NULL)
        {
            if(isOdd == true)
            {
                if(prevOdd != NULL)
                    prevOdd->next = curr;
                
                prevOdd = curr;
            }
            else
            {
                if(evenHead == NULL)
                    evenHead = curr;

                if(prevEven != NULL)
                    prevEven->next = curr;
                
                prevEven = curr;
            }

            isOdd = !isOdd;
            curr = curr->next;
        }

        prevEven->next = NULL;
        prevOdd->next = evenHead;
        
        return head;
    }
};