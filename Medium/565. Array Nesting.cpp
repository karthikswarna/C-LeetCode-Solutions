class Solution {
public:
    // Like a graph problem. Solve it for an example to understand.
    // We just have to find the size of largest connected component.
    int arrayNesting(vector<int>& nums)
    {
        int n = nums.size();
        int maxLen = 0;
        vector<bool> set(n, false);

        // Construct S[i] for [0,n). Here, each of the non-zero length'ed s[i] is a connected component in the graph.
        for(int i = 0; i < n; ++i)
        {
            int next = nums[i];
            int length = 0;

            while(set[next] == false)
            {
                set[next] = true;
                next = nums[next];
                ++length;
            }
            
            maxLen = std::max(length, maxLen);
        }
        
        return maxLen;
    }
};