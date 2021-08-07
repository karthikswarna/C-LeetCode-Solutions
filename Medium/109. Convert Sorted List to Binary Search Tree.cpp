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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        if(head == NULL) return NULL;

        // Calculate list's length;
        ListNode* curr = head;
        int len = 0;
        while(curr != NULL)
        {
            curr = curr-> next;
            len++;
        }
        
        // Construct Tree;
        return sortedListToBST(head, len);
    }

    TreeNode* sortedListToBST(ListNode* curr_list, int list_len)
    {
        if(curr_list == NULL || list_len == 0) return NULL;

        int i = 0;
        ListNode* temp = curr_list;
        while(i < list_len/2)
        {
            temp = temp->next;
            i++;
        }

        TreeNode* curr_tree = new TreeNode(temp->val);
        curr_tree->left = sortedListToBST(curr_list, list_len / 2);
        curr_tree->right = sortedListToBST(temp->next, 
                        (list_len % 2 == 0) ? (list_len / 2 - 1) : (list_len / 2));
        
        return curr_tree;
    }
};