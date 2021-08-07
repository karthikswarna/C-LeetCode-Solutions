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
    vector<TreeNode*> allPossibleFBT(int n)
    {
        if(n % 2 == 0)
            return vector<TreeNode*>{};
        
        unordered_map<int, vector<TreeNode*>> memo;
        allPossibleFBT(n, memo);
        
        // for(int i = 1; i <= n; i += 2)
        //     cout << i << ": " << memo[i].size() << endl;

        return memo[n];
    }

    void allPossibleFBT(int n, unordered_map<int, vector<TreeNode*>> &memo)
    {
        if(memo.find(n) != memo.end())
            return;
        
        if(n == 1)
        {
            memo[1] = vector<TreeNode*>{new TreeNode()};
            return;
        }   
        
        vector<TreeNode*> temp_result;
        int multiple = 1;
        while(n - 2*multiple >= n/2)
        {
            int large = n - 2 * multiple;
            int small = 2 * multiple - 1;

            allPossibleFBT(large, memo);
            allPossibleFBT(small, memo);
            
            for(int i = 0; i < memo[small].size(); i++)
            {                    
                for(int j = 0; j < memo[large].size(); j++)
                {
                    // For balanced trees, avoid repetitive trees (same structured trees are generated multiple times without this condition)
                    if((small == large) && (j < i)) continue;

                    TreeNode* curr = new TreeNode();
                    curr->left = memo[small][i];
                    curr->right = memo[large][j];
                    temp_result.push_back(curr);
                    
                    // If two brances are same, only one permutation is possible.
                    if(memo[small][i] == memo[large][j]) continue;

                    TreeNode* curr2 = new TreeNode();
                    curr2->left = memo[large][j];
                    curr2->right = memo[small][i];
                    temp_result.push_back(curr2);
                }
            }
            
            multiple++;
        }
        
        memo[n] = temp_result;
    }
};