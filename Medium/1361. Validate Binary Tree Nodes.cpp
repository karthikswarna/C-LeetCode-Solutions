class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        vector<int> inDegree(n, 0);
        for(int i = 0; i < n; ++i)
        {
            if(leftChild[i] != -1) ++inDegree[leftChild[i]];
            if(rightChild[i] != -1) ++inDegree[rightChild[i]];
        }
        
        int root = n;
        for(int i = 0; i < n; ++i)
        {
            if(inDegree[i] == 0)
            {
                if(root != n) return false; // If root is already set previously.
                root = i;
            }
            else if(inDegree[i] > 1)
                return false;
        }
        
        if(root == n) return false;         // Root not found.
        
        int visitedNodes = 0;
        return validatePreorder(root, visitedNodes, leftChild, rightChild) && visitedNodes == n;
    }
    
    bool validatePreorder(int root, int& visitedNodes, vector<int>& leftChild, vector<int>& rightChild)
    {
        if(root == -1) return true;
        
        ++visitedNodes;
        int left = validatePreorder(leftChild[root], visitedNodes, leftChild, rightChild);
        int right = validatePreorder(rightChild[root], visitedNodes, leftChild, rightChild);
    
        return left && right;
    }
};