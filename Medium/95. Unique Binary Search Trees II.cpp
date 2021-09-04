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
    vector<TreeNode*> recurse(int start, int end)
    {
        if(start > end) return vector<TreeNode*>{NULL};
        
        vector<TreeNode*> ans;
        for(int root = start; root <= end; ++root)
        {
            vector<TreeNode*> left = recurse(start, root - 1);
            vector<TreeNode*> right = recurse(root + 1, end);
            
            for(auto nl :left)
            {
                for(auto nr :right)
                {
                    TreeNode* curr = new TreeNode(root);
                    curr->left = nl;
                    curr->right = nr;
                    ans.push_back(curr);
                }
            }
        }

        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n)
    {
        // First Solution(Cannot avoid duplicates using this approach)
//         vector<bool> isInserted(n + 1, false);
        
//         vector<TreeNode*> result;
//         for(int i = 1; i <= n; ++i)
//             generateTrees(i, NULL, isInserted, result);
        
//         return result;

        // Second Approach.
        return recurse(1, n);
    }
    
    void generateTrees(int currVal, TreeNode* root, vector<bool> isInserted, vector<TreeNode*>& result)
    {
        root = insert(root, currVal);
        isInserted[currVal] = true;
        
        bool done = true;
        for(int i = 1; i < isInserted.size(); ++i)
        {
            if(!isInserted[i])
            {
                done = false;
                TreeNode* newTree = copyTree(root);
                generateTrees(i, newTree, isInserted, result);
            }
        }
        
        if(done) result.push_back(root);
    }
    
    TreeNode* insert(TreeNode* root, int val)
    {
        if(root == NULL)
        {
            TreeNode* curr = new TreeNode(val);
            return curr;
        }
        
        if(root->val < val)
            root->right = insert(root->right, val);
        else
            root->left = insert(root->left, val);
    
        return root;
    }
    
    TreeNode* copyTree(TreeNode* root)
    {
        if(root == NULL) return NULL;
        
        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = copyTree(root->left);
        newRoot->right = copyTree(root->right);
        
        return newRoot;
    }
};