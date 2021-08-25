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
    // Without using map - reverse preorder traversal.
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        preorder(root, 1, result);
        
        return result;
    }

    void preorder(TreeNode *root, int level, vector<int>& result)
    {
        if(root == NULL) return;

        if(result.size() < level) 
            result.push_back(root->val);
        
        // Reverse preorder traversal.
        preorder(root->right, level + 1, result);
        preorder(root->left, level + 1, result);
    }
    
    // My Original Solution using O(N) space
//     vector<int> rightSideView(TreeNode* root)
//     {
//         map<int, int> M;
//         preorder(root, 0, M);

//         vector<int> result;
//         for(auto &i: M)
//             result.push_back(i.second);
//         return result;
//     }

//     void preorder(TreeNode* root, int level, map<int, int>& M)
//     {
//         if(root == NULL) return;
    
//         M[level] = root->val;

//         preorder(root->left, level + 1, M);
//         preorder(root->right, level + 1, M);
//     }
};