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
    TreeNode* pruneTree(TreeNode* root)
    {
        if(!preorder(root))
            return NULL;
        
        return root;
    }

    bool preorder(TreeNode* root)
    {
        if(root == NULL) return false;
        
        bool left = preorder(root->left);
        if(!left)
            root->left = NULL;

        bool right = preorder(root->right);
        if(!right)
            root->right = NULL;

        if(left || right || root->val == 1)
            return true;

        return false;
    }

};