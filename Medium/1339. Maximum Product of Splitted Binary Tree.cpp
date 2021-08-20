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
    long maxProd = INT_MIN;
    long totalSum = 0;

    int maxProduct(TreeNode* root)
    {
        totalSum = getTreeSum(root);
        
        maxSplit(root);
        
        return maxProd % (int)(1e9 + 7);
    }
    
    long maxSplit(TreeNode* root)
    {
        if(root == NULL) return 0;

        long leftSubtreeSum = maxSplit(root->left);
        long rightSubtreeSum = maxSplit(root->right);
        
        maxProd = std::max({(totalSum - leftSubtreeSum) * leftSubtreeSum,
                            (totalSum - rightSubtreeSum) * rightSubtreeSum,
                             maxProd});

        return root->val + leftSubtreeSum + rightSubtreeSum;
    }
    
    long getTreeSum(TreeNode* root)
    {
        if(root == NULL) return 0;

        return root->val + getTreeSum(root->left) + getTreeSum(root->right);
    }
};