class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        result.push_back(vector<int>{1});
        
        for(int i = 2; i <= numRows; ++i)
        {
            vector<int> temp(i, 1);
            for(int j = 1; j < i - 1; ++j)      // First two elements are 1, calculate remaining elements.
            {
                temp[j] = result.back()[j] + result.back()[j - 1];
            }
            
            result.push_back(temp);
        }
        
        return result;
    }
};