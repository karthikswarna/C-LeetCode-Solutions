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
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        map<int, vector<pair<int, int>>> verOrder;
        preorder(root, 0, 0, verOrder);
        
        for_each(verOrder.begin(), verOrder.end(), [](auto &distToNodes)
        {
            sort(distToNodes.second.begin(), distToNodes.second.end(), [](auto &pair1, auto &pair2)
            {
                return (pair1.second < pair2.second) 
                    || ((pair1.second == pair2.second) && (pair1.first < pair2.first));
            });
        });

        vector<vector<int>> result;
        for(auto distToNodes: verOrder)
        {
            vector<int> temp;
            for(auto node: distToNodes.second)
                temp.push_back(node.first);
            result.push_back(temp);
        }

        return result;
    }
    
    void preorder(TreeNode* root, int depth, int dist, map<int, vector<pair<int, int>>>& verOrder)
    {
        if(root == NULL) return;
        
        verOrder[dist].push_back(make_pair(root->val, depth));
        
        preorder(root->left, depth + 1, dist - 1, verOrder);
        preorder(root->right, depth + 1, dist + 1, verOrder);
    }
};