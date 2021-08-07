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
    TreeNode* prev = NULL;
    int minDiff = INT_MAX;

    int minDiffInBST(TreeNode* root)
    {
        inorder(root);
        return minDiff;
    }
    
    void inorder(TreeNode* root)
    {
        if(root == NULL) return;
        
        minDiffInBST(root->left);

        if(prev != NULL)
        {
            int diff = root->val - prev->val;
            if(diff < minDiff)
                minDiff = diff;
        }
        
        prev = root;

        minDiffInBST(root->right);
    }
};