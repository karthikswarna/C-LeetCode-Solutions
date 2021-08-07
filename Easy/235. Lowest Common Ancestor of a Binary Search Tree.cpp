/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        postOrder(root, p, q);
        return ans;
    }
    
    bool postOrder(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL) return false;
        
        bool left = postOrder(root->left, p, q);
        bool right = postOrder(root->right, p, q);
        
        // If ans in not found previously, and found now.
        if(ans == NULL && (left && right || 
                           left && (root == p || root == q) || 
                           right && (root == p || root == q)))
        {
            ans = root;
            return true;
        }

        if(root == p || root == q)
            return true;
            
        return left || right;
    }
};