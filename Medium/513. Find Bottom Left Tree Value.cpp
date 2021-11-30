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
    int bottomLeftVal;
    int maxDepth = 0;
public:
    int findBottomLeftValue(TreeNode* root)
    {
        bottomLeftVal = root->val;
        preorder(root, 0);
        return bottomLeftVal;
    }
    
    void preorder(TreeNode* root, int depth)
    {
        if(root == NULL) return;
        
        if(depth > maxDepth)
        {
            maxDepth = depth;
            bottomLeftVal = root->val;
        }
        
        preorder(root->left, depth + 1);
        preorder(root->right, depth + 1);
    }
};