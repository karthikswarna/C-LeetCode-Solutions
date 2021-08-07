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
    int maxCount = INT_MIN;
    int currCount = 0;
    TreeNode* prev;

    vector<int> findMode(TreeNode* root)
    {
        vector<int> result;
        inorder(root, result);
        return result;
    }
    
    void inorder(TreeNode* root, vector<int> &result)
    {
        if(root == NULL) return;
        
        // Traverse left subtree.
        inorder(root->left, result);
        
        if(prev != NULL)
        {
            if(prev->val == root->val) currCount++;
            else currCount = 1;
        }
        else currCount = 1;

        prev = root;

        // Update global Vars
        if(currCount > maxCount)
        {
            maxCount = currCount;
            result.clear();
            result.push_back(root->val);
        }
        else if(currCount == maxCount)
            result.push_back(root->val);

        
        // Traverse right subtree.
        inorder(root->right, result);
    }
};