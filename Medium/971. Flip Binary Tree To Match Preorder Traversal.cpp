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
    vector<int> flipped;
     int voyageIdx = 0;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage)
    {
        return flipNodes(root, voyage) ? flipped : vector<int>{-1};
    }

    // We do not actually swap the child nodes, we simulate it through traversing in the opposite order.
    bool flipNodes(TreeNode* root, vector<int>& voyage)
    {
        if(root == NULL) return true;
        
        if(root->val != voyage[voyageIdx++]) return false;

        // voyageIdx+1 will be < voyage.size(), since we visit all nodes exactly once.
        if(root->left != NULL && voyage[voyageIdx] != root->left->val)
        {
            flipped.push_back(root->val);
            return flipNodes(root->right, voyage) && flipNodes(root->left, voyage);
        }

        return flipNodes(root->left, voyage) && flipNodes(root->right, voyage);
    }
};