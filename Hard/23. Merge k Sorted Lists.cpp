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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0) return NULL;
        
        int len = lists.size();
        while(len > 1)
        {
            for(int i = 0; i < len / 2; ++i)
                lists[i] = merge(lists[i], lists[len - 1 - i]);

            len = (len + 1) / 2;
        }
        
        return lists[0];
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        if(head1 == NULL && head2 == NULL) return NULL;
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        ListNode* head = new ListNode();
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
};