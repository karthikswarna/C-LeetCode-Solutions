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
    int h = -1;
    bool foundLastNode = false;
public:
    int countNodes(TreeNode* root)
    {
        if(root == NULL) return 0;

        // Find the height of the tree.
        TreeNode* curr = root;
        while(curr != NULL)
        {
            curr = curr->left;
            ++h;
        }
        
        int maxNodes = pow(2, h + 1) - 1;
        return maxNodes - countLastLevel(root, 0);;
    }
    
    int countLastLevel(TreeNode* root, int level)
    {
        if(foundLastNode) return 0;
        if(level == h && root == NULL) return 1;
        if(level == h && root != NULL) return 0;

        int right = countLastLevel(root->right, level + 1);
        int left = countLastLevel(root->left, level + 1);
        
        if(left + right < 2) foundLastNode = true;
        
        return left + right;
    }
};