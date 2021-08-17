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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if(root == NULL) return result;

        deque<TreeNode*> Q;
        Q.push_back(root);

        bool flag = true;          // If flag is false, visit right children first, left child otherwise.

        while(!Q.empty())
        {
            // Store the length of current level so that we can pop those nodes later.
            int len = Q.size();

            // Push next level to the queue.
            vector<int> temp;
            for(auto it = Q.rbegin(); it != Q.rend(); ++it)
            {
                if(flag)
                {
                    if((*it)->left != NULL)
                        Q.push_back((*it)->left);
                    if((*it)->right != NULL)
                        Q.push_back((*it)->right);
                }
                else
                {
                    if((*it)->right != NULL)
                        Q.push_back((*it)->right);
                    if((*it)->left != NULL)
                        Q.push_back((*it)->left);
                }

                temp.push_back((*it)->val);
            }

            // Remove the current level from the queue.
            while(len > 0)
            {
                Q.pop_front();
                --len;
            }
            
            // Push the current level to the result.
            result.push_back(temp);
            
            flag = !flag;
        }

        return result;
    }
};