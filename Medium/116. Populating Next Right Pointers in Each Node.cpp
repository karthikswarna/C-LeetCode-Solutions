/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    // Level-Order Traversal
    Node* connect(Node* root)
    {
        if(root == NULL) return NULL;

        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int len = Q.size();
            Node* prev = NULL;
            Node* curr;
            while(len > 0)
            {
                curr = Q.front();
                Q.pop();
                
                if(prev != NULL)
                    prev->next = curr;
                prev = curr;
            
                if(curr->left != NULL)
                    Q.push(curr->left);
                if(curr->right != NULL)
                    Q.push(curr->right);

                --len;
            }

            prev->next = NULL;
        }
        
        return root;
    }
    
    // Preorder Traversal
    Node* connect(Node* root)
    {
        if (root == NULL || root->left == NULL) return root;
        
        
        // Set left child's next.
        root->left->next = root->right;

        // Set right child's next.
        if (root->next)
            root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);
        
        return root;
    }
};