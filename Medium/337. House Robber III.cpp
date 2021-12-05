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


// Reference: https://codeforces.com/blog/entry/20935
// Look at problem 1 in the post.
class Solution
{
    unordered_map<TreeNode*, int> dp1;
    unordered_map<TreeNode*, int> dp2;

public:
    int rob(TreeNode* root)
    {
        optimalRobberyPlan(root);
        return max(dp1[root], dp2[root]);
    }

    void optimalRobberyPlan(TreeNode* root)
    {
        if(root == NULL) return;

        optimalRobberyPlan(root->left);
        optimalRobberyPlan(root->right);
        
        dp1[root] += root->val + dp2[root->left] + dp2[root->right];
        dp2[root] += max(dp1[root->left], dp2[root->left]) + max(dp1[root->right], dp2[root->right]);
    }
};