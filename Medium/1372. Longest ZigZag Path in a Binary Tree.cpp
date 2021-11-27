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
    int longestZigZag(TreeNode* root)
    {
        return max(zigZagTraverse(root, 0, false), zigZagTraverse(root, 0, true));
    }

    int zigZagTraverse(TreeNode* root, int currPathLength, bool isRightChild)
    {
        if(root == NULL) return currPathLength - 1;     // Path Length is the number of edges.
 
        // Similar to Kadane's Algo
        // Continue traversing in the oposite direction and increment length.
        // Or, start a new traversal in the same direction, resetting length to one.
        int len;
        if(isRightChild)
            len = max({zigZagTraverse(root->left, currPathLength + 1, false), 
                      zigZagTraverse(root->right, 1, true)});
        else
            len = max({zigZagTraverse(root->right, currPathLength + 1, true), 
                      zigZagTraverse(root->left, 1, false)});

        return len;
    }
};