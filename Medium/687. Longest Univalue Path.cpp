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
    int maxLen = 0;
public:
    int longestUnivaluePath(TreeNode* root)
    {
        longestNodePath(root);
        return maxLen <= 1 ? 0 : maxLen - 1;      // Number of edges = Number of nodes - 1;
    }

    int longestNodePath(TreeNode* root)
    {
        if(root == NULL) return 0;

        int leftLen = longestNodePath(root->left);
        int rightLen = longestNodePath(root->right);

        int returnVal;

        if(root->left != NULL && root->right != NULL && 
           root->val == root->left->val && root->val == root->right->val)
        {
            maxLen = max(leftLen + rightLen + 1, maxLen);
            returnVal = max(leftLen, rightLen) + 1;
        }
        
        else if(root->left != NULL && root->val == root->left->val)
        {
            maxLen = max(leftLen + 1, maxLen);
            returnVal = leftLen + 1;
        }
        
        else if(root->right != NULL && root->val == root->right->val)
        {
            maxLen = max(rightLen + 1, maxLen);
            returnVal = rightLen + 1;
        }

        else
        {
            maxLen = max(1, maxLen);
            returnVal = 1;
        }

        return returnVal;
    }
};