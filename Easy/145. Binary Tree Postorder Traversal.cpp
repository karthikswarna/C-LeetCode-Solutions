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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> postorder;
        if(root == NULL) return postorder;
        
        stack<TreeNode*> S;
        TreeNode* curr = root;
        TreeNode* prev = NULL;

        while(curr != NULL || !S.empty())
        {
            while(curr != NULL)
            {
                S.push(curr);
                curr = curr->left;
            }
            
            TreeNode* top = S.top();
            if(top->right != NULL && prev != top->right)
                curr = top->right;

            else
            {
                S.pop();
                postorder.push_back(top->val);
                prev = top;
            }
        }
        
        return postorder;
    }
};