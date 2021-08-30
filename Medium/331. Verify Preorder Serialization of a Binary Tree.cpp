class Solution {
public:
    int currIdx = -1;
    bool isValidSerialization(string preorder)
    {
        // Tokenise the input string and create a list of node values.
        vector<string> input;

        stringstream stream(preorder);
        string temp;
        while(getline(stream, temp, ','))
            input.push_back(temp);
        
        
        // Do a preorder traversal and verify the validity of given input.
        bool result = traverse(input);
        
        // If some input remains even after traversing the tree, it is invalid.
        if(currIdx != input.size() - 1) return false;
        
        return result;
    }

    bool traverse(vector<string>& preorder)
    {
        currIdx += 1;

        if(currIdx >= preorder.size()) return false;
        if(preorder[currIdx] == "#") return true;
        
        return traverse(preorder) && traverse(preorder);;
    }
};