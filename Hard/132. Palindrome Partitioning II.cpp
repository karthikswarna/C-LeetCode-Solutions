class Solution {
public:
    int minCut(string s)
    {
        vector<int> memo(s.size(), -1);
        return minCut(s, 0, s.size() - 1, memo);
    }
    
    int minCut(string &s, int low, int high, vector<int> &memo)
    {
        if(isPalindrome(s, low, high)) return 0;
        if(memo[low] != -1) return memo[low];
    
        int minCutCount = INT_MAX;
        for(int i = low; i <= high; ++i)
        {
            if(isPalindrome(s, low, i))
                minCutCount = std::min(1 + minCut(s, i + 1, high, memo), minCutCount);
        }
        
        return memo[low] = minCutCount;
    }
    
    bool isPalindrome(string &s, int low, int high)
    {
        while (low < high)
            if (s[low++] != s[high--])
                return false;
        
        return true;
    }
};