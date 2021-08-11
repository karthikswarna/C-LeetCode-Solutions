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
    bool isValidBST(TreeNode* root)
    {
        if(root == NULL) return true;

        bool left = isValidBST(root->left);

        bool curr = false;
        if(prev == NULL || prev->val < root->val)
            curr = true;
        prev = root;

        bool right = isValidBST(root->right);

        return left && curr && right;
    }
};