class Solution {
public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;
        
        for(auto &ch: columnTitle)
            result = (result * 26) + ((int)ch - 64);
    
        return result;
    }
};