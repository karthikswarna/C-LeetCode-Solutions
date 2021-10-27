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
    TreeNode* xParent = NULL;
    TreeNode* yParent = NULL;
    int xDepth = INT_MAX;
    int yDepth = INT_MAX;
public:
    bool isCousins(TreeNode* root, int x, int y)
    {
        preorder(root, NULL, 0, x, y);

        if(xDepth == yDepth && xParent != yParent)
            return true;

        return false;
    }
    
    void preorder(TreeNode* child, TreeNode* parent, int depth, int x, int y)
    {
        if(child == NULL || (xDepth != INT_MAX && yDepth != INT_MAX)) return;
        
        if(child->val == x)
        {
            xParent = parent;
            xDepth = depth;
        }
        else if(child->val == y)
        {
            yParent = parent;
            yDepth = depth;
        }

        preorder(child->left, child, depth + 1, x, y);
        preorder(child->right, child, depth + 1, x, y);        
    }
};