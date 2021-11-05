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
    string smallestStr = "";
public:
    string smallestFromLeaf(TreeNode* root)
    {
        Util(root, "");
        return smallestStr;
    }
    
    void Util(TreeNode* root, string currStr)
    {
        if(root == NULL) return;

        currStr = (char)(97 + root->val) + currStr;
        if(root->left == NULL && root->right == NULL) 
        {
            if(smallestStr == "" || currStr < smallestStr)
                smallestStr = currStr;

            return;
        }

        Util(root->left, currStr);
        Util(root->right, currStr);
    }
};