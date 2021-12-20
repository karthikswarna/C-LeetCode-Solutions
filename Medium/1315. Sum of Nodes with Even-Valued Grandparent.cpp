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
    int sumEvenGrandparent(TreeNode* root)
    {
        return getSum(root, -1, -1);
    }
    
    int getSum(TreeNode* root, int parentVal, int grandparentVal)
    {
        if(root == NULL) return 0;
        
        int sum = 0;
        if(grandparentVal % 2 == 0)
            sum += root->val;

        sum += getSum(root->left, root->val, parentVal) + getSum(root->right, root->val, parentVal);

        return sum;
    }
};