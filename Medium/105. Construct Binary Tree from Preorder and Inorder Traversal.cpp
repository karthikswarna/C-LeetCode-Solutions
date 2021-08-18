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
    // Preorder[a, b] Inorder[c, d]
    // [root][......left......][...right..]  --- Preorder
    //                       ^               --- This is   `a + id`
    // [......left......][root][...right..]  --- Inorder
    //                     ^                 --- This is `c - id`
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int N = inorder.size();
        unordered_map<int, int> M;
        for(int i = 0; i < N; ++i)
            M[inorder[i]] = i;
        
        return traverse(preorder, inorder, 0, N - 1, 0, N - 1, M);
    }
    
    TreeNode* traverse(vector<int> &preorder, vector<int>& inorder, int a, int b, int c, int d, unordered_map<int, int>& M)
    {
        TreeNode* root = new TreeNode(preorder[a]);

        if(a == b) return root;     // No children
        
        int id = M[preorder[a]];

        if(c < id)                 // c == id -->  No left children
            root->left = traverse(preorder, inorder, a + 1, a + (id - c), c, id - 1, M);
        
        if(a + id - c < b)        // a + (id - c) == b --> No right child
            root->right = traverse(preorder, inorder, a + (id - c) + 1, b, id + 1, d, M);
        
        return root;
    }
};