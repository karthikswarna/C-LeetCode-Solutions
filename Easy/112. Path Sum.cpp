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
    bool hasPathSum(TreeNode* root, int targetSum, int currSum = 0)
    {
        if(root == NULL) return false;
        
        currSum += root->val;

        if(root->left == NULL && root->right == NULL && currSum == targetSum) return true;
        
        return hasPathSum(root->left, targetSum, currSum) || hasPathSum(root->right, targetSum, currSum);
    }
};