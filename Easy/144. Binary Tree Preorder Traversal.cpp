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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> preorder;
        if(root == NULL) return preorder;
        
        stack<TreeNode*> S;
        S.push(root);
        while(!S.empty())
        {
            TreeNode* top = S.top();
            S.pop();

            if(top != NULL)
            {
                preorder.push_back(top->val);
                S.push(top->right);
                S.push(top->left);
            }
        }
        
        return preorder;
    }
};