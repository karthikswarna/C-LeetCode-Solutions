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
public:
    int maxPathSum(TreeNode* root)
    {
        int maxSum = INT_MIN;
        maxPathSumUtil(root, maxSum);
        return maxSum;
    }

    int maxPathSumUtil(TreeNode* root, int& maxSum)
    {
        if(root == NULL) return 0;

        int leftSum = maxPathSumUtil(root->left, maxSum);
        int rightSum = maxPathSumUtil(root->right, maxSum);

        if(leftSum < 0) leftSum = 0;
        if(rightSum < 0) rightSum = 0;

        if(maxSum < leftSum + rightSum + root->val)
            maxSum = leftSum + rightSum + root->val;

        // Getting maximum valued half of the path.
        root->val += std::max(leftSum, rightSum);

        // Function updates the value of maxSum with the sum of path rooted at the root.
        // BUT this function returns that half of path for which maximum value can be obtained. 
        // This is done so that the parent node can continue the path to create much better path.
        return root->val;
    }
};