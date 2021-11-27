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
class subTreeSum
{
public:
    int sum = 0;
    bool isBst = true;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    subTreeSum(int sum, bool isBst) 
        : sum {sum}
        , isBst {isBst}
          { }
};

class Solution
{
public:
    int maxSumBST(TreeNode* root)
    {
        int maxBSTSum = 0;
        findMaxSumBST(root, maxBSTSum);
        return maxBSTSum;
    }
    
    subTreeSum findMaxSumBST(TreeNode* root, int& maxBSTSum)
    {
        if(root == NULL) return subTreeSum(0, true);

        subTreeSum leftSubTree = findMaxSumBST(root->left, maxBSTSum);
        subTreeSum rightSubTree = findMaxSumBST(root->right, maxBSTSum);

        subTreeSum currTree(root->val + leftSubTree.sum + rightSubTree.sum, false);
        currTree.minVal = min(leftSubTree.minVal, root->val);   // root->val will be min when root->left is NULL.
        currTree.maxVal = max(rightSubTree.maxVal, root->val);

        if(leftSubTree.isBst && rightSubTree.isBst 
           && (root->val > leftSubTree.maxVal)
           && (root->val < rightSubTree.minVal))
        {
            currTree.isBst = true;
            maxBSTSum = max(currTree.sum, maxBSTSum);
        }

        return currTree;
    }

};