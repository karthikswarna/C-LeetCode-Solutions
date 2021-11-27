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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return buildTreeUtil(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    TreeNode* buildTreeUtil(vector<int>& inorder, vector<int>& postorder, int start1, int end1, int start2, int end2)
    {
        if(start1 > end1 || start2 > end2) return NULL;
        
        int rootIdx = find(inorder.begin(), inorder.end(), postorder[end2]) - inorder.begin();
        TreeNode* root = new TreeNode(postorder[end2]);
        
        root->left = buildTreeUtil(inorder, postorder, start1, rootIdx - 1, start2, start2 + (rootIdx - start1) - 1);
        root->right = buildTreeUtil(inorder, postorder, rootIdx + 1, end1, start2 + (rootIdx - start1), end2 - 1);

        return root;
    }
};