/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> result;
        if(root == NULL) return result;

        Node* sentinel = new Node(-1);
        vector<int> V;
        
        queue<Node*> Q;
        Q.push(root);
        Q.push(sentinel);
        
        while(!Q.empty())
        {
            Node* front = Q.front();
            Q.pop();
   
            if(front->val == -1)
            {
                result.push_back(V);
                V.clear();

                if(Q.empty()) break; // For the last level, after popping -1, Q will be empty. So we can break

                Q.push(sentinel);
            }
            else
            {
                for(const auto child: front->children)
                    Q.push(child);
                V.push_back(front->val);
            }
        }
        
        return result;
    }
};