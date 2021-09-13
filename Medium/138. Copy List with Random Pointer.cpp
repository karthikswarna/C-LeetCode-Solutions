/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Use Hash Table to store the new nodes' pointers. Time: O(N), Space: O(N)
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*, Node*> M;
        Node* curr = head;
        while(curr != NULL)
        {
            M[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // Set pointers of new copy nodes.
        curr = head;
        while(curr != NULL)
        {
            M[curr]->next = M[curr->next];
            M[curr]->random = M[curr->random];
            curr = curr->next;
        }
        
        return M[head];
    }
    // Create Duplicate Nodes and interweave them. Time: O(N), Space: O(1).
//     Node* copyRandomList(Node* head)
//     {
//         if(head == NULL) return NULL;

//         Node* curr = head;
//         Node* oldNext = NULL;
        
//         // Create a duplicate for each node after its occurance in the list.
//         while(curr != NULL)
//         {
//             Node* dupl = new Node(curr->val);
//             oldNext = curr->next;
//             curr->next = dupl;
//             dupl->next = oldNext;
//             curr = oldNext;
//         }
        
//         // Set the random pointers of the duplicate nodes.
//         curr = head->next;
//         Node* prev = head;
//         while(curr != NULL)
//         {
//             curr->random = (prev->random == NULL) ? NULL : prev->random->next;
//             prev = curr->next;
//             curr = (curr->next == NULL) ? NULL : curr->next->next;
//         }
        
//         // Separate the Original List from the Duplicate List
//         Node* newHead = head->next;
//         curr = head;
//         while(curr != NULL)
//         {
//             oldNext = curr->next;
//             curr->next = (curr->next == NULL) ? NULL : curr->next->next;
//             curr = oldNext;
//         }
        
//         return newHead;
//     }
};