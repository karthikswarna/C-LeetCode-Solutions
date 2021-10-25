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
class Solution
{
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        maxChildPath(root);
        return diameter;
    }
    
    int maxChildPath(TreeNode* root)
    {
        if(root == NULL) return 0;

        int maxLeft = maxChildPath(root->left);
        int maxRight = maxChildPath(root->right);
        
        diameter = max(maxLeft + maxRight, diameter);
        
        return 1 + max(maxLeft, maxRight);
    }
};