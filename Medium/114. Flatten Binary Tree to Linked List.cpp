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
    TreeNode* prev = new TreeNode();    // Dummy node to avoid the (prev != NULL) check

public:
    void flatten(TreeNode* root)
    {
        if(root == NULL) return;

        // if(prev != NULL)
        prev->right = root;
        prev = root;

        // Save it, because it will be modified while traversing left subtree;
        TreeNode* right = root->right;

        flatten(root->left);
        flatten(right);

        root->left = NULL;
    }
};