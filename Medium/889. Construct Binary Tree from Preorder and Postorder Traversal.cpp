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
    // [root][......left......][...right..]  --- Preorder
    //                       ^               --- This is   `a + (id - c + 1)`
    // [......left......][...right..][root]  --- Postorder
    //                 ^                     --- This is `id`

    // preorder[a, b], postorder[c, d] --> let id be the index of left child in postorder
    // postorder[c, id] --> postorder of left subtree
    // preorder[a + 1, a + (id - c + 1)] --> preorder of left subtree

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
    {
        int N = postorder.size();
        unordered_map<int, int> M;
        for(int i = 0; i < N; ++i)
            M[postorder[i]] = i;
        
        return traverse(preorder, postorder, 0, N - 1, 0, N - 1, M);
    }
    
    TreeNode* traverse(vector<int> &preorder, vector<int> &postorder, int a, int b, int c, int d, unordered_map<int, int>& M)
    {
        TreeNode* root = new TreeNode(preorder[a]);
        
        if(a == b) return root;

        int leftChildIdx = M[preorder[a + 1]];
        root->left = traverse(preorder, postorder, a + 1, a + (leftChildIdx - c + 1), c, leftChildIdx, M);

        if(leftChildIdx + 1 == d) return root;  // There is no right subtree.

        root->right = traverse(preorder, postorder, a + (leftChildIdx - c + 2), b, leftChildIdx + 1, d - 1, M);
        
        return root;
    }
};