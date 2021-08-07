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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<int> path;
        return pathSum(root, targetSum, path, 0);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum, vector<int> &path, int cumSum = 0)
    {
        // Base Case I
        if(root == NULL) return vector<vector<int>>{};

        // Base Case II
        if(root->left == NULL && root->right == NULL)
        {       
            if(cumSum + root->val == targetSum)
            {
                auto temp = path;
                temp.push_back(root->val);
                return vector<vector<int>>{temp};
            }
            else
                return vector<vector<int>>{};
        }

        path.push_back(root->val);
        auto left = pathSum(root->left, targetSum, path, cumSum + root->val);
        auto right = pathSum(root->right, targetSum, path, cumSum + root->val);
        path.pop_back();

        left.insert( left.end(), right.begin(), right.end() );
        return left;
    }
};