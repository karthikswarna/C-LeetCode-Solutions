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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> inorder;
        if(root == NULL) return inorder;

        stack<TreeNode*> S;
        TreeNode* curr = root;

        while(!S.empty() || curr != NULL)
        {
            while(curr != NULL)
            {
                S.push(curr);
                curr = curr->left;
            }
            
            TreeNode* top = S.top();
            S.pop();
            inorder.push_back(top->val);
            curr = top->right;
        }
        
        return inorder;
    }
};