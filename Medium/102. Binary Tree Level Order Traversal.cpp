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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if(root == NULL) return result;

        vector<int> temp;

        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int count = Q.size();
            while(count > 0)
            {                
                TreeNode* front = Q.front();
                Q.pop();
                
                temp.push_back(front->val);
                
                if(front->left != NULL)
                    Q.push(front->left);

                if(front->right != NULL)
                    Q.push(front->right);

                --count;
            }

            result.push_back(temp);
            temp.clear();
        }
        
        return result;
    }        
};