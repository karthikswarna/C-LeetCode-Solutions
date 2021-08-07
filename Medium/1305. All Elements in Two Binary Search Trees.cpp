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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> order;
        inorder(root1, order);
        inorder(root2, order);
        sort(order.begin(), order.end());
        return order;
    }
    
    void inorder(TreeNode* root, vector<int>& order)
    {
        if(root == NULL) return;
        
        inorder(root->left, order);
        order.push_back(root->val);
        inorder(root->right, order);
    }
};