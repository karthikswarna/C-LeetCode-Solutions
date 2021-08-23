/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string result;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int len = Q.size();
            while(len > 0)
            {
                TreeNode* front = Q.front();
                Q.pop();
                
                if(front != NULL)
                {
                    Q.push(front->left);
                    Q.push(front->right);
                }

                if(front == NULL) result += ",";
                else              result += to_string(front->val) + ',';
                
                --len;
            }
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        TreeNode* root = NULL;

        queue<TreeNode**> Q;
        TreeNode** prev = &root;

        stringstream sstream(data);
        string intermediate;

        while(getline(sstream, intermediate, ','))
        {
            if(intermediate == "")
                *prev = NULL;

            else
            {
                TreeNode* curr = new TreeNode(stoi(intermediate));
                if(prev != NULL)
                    *prev = curr;
                else
                    root = curr;

                Q.push(&(curr->left));
                Q.push(&(curr->right));
            }
            
            prev = Q.front();
            Q.pop();

        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));