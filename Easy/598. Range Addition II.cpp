class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops)
    {
        // Initialize with dimensions (not INT_MAX). 
        // if ops is empty then all the cells have maximum value.
        int minX = m;
        int minY = n;
        for(auto &op: ops)
        {
            minX = std::min(op[0], minX);
            minY = std::min(op[1], minY);
        }
        
        return minX * minY;
    }
};