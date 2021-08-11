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
    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL) return true;

        return symmetricTest(root->left, root->right);
    }
    
    bool symmetricTest(TreeNode* left_root, TreeNode* right_root)
    {
        if(left_root == NULL && right_root == NULL) return true;     // Both are NULL

        if(left_root == NULL || right_root == NULL) return false;    // Only one of them is null.
    
        if(left_root->val != right_root->val) return false;         // Values are not equal.
        
        return symmetricTest(left_root->left, right_root->right) && // Check for subtrees.
               symmetricTest(left_root->right, right_root->left);
    }
};