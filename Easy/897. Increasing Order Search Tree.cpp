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
    TreeNode* cur;
    TreeNode* increasingBST(TreeNode* root)
    {
        // Temporary node to hold the answer.
        TreeNode* ans = new TreeNode();
        
        // Set the current pointer to the temporary node.
        cur = ans;
        
        inorder(root);
        return ans->right;
    }

    void inorder(TreeNode* node)
    {
        if(node == NULL) return;
        
        inorder(node->left);

        node->left = NULL;
        cur->right = node;
        cur = node;

        inorder(node->right);
    }
};