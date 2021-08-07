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
    int curr = 0;

    TreeNode* bstFromPreorder(vector<int>& preorder, int parentVal = INT_MAX)
    {
        // Second condition is to stop the recursion on the left subtree.
        if(curr >= preorder.size() || preorder[curr] > parentVal) return NULL;

        TreeNode* currNode = new TreeNode(preorder[curr++]);

        currNode->left = bstFromPreorder(preorder, currNode->val);
        
        currNode->right = bstFromPreorder(preorder, parentVal);

        return currNode;
    }
};