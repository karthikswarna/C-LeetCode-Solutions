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
    bool findTarget(TreeNode* root, int k)
    {
        unordered_set<int> S;
        return inorder(root, k, S);
    }
    
    bool inorder(TreeNode* root, int k, unordered_set<int>& S)
    {
        if(root == NULL) return false;
        
        bool left = inorder(root->left, k, S);
        
        if(S.find(k - root->val) != S.end())
            return true;
        S.insert(root->val);

        bool right = inorder(root->right, k, S);
        
        return left || right;
    }
};