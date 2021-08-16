class Solution {
public:
    string minWindow(string s, string t)
    {
        if(t.size() > s.size()) return "";


        // Build a map on count of characters in t. Vector can be used for better performance.
        unordered_map<char, int> T;
        for(auto &i: t)
            ++T[i];
    
        int minLen = INT_MAX;
        int ansStart = INT_MAX;
        int ansEnd = INT_MAX;

        unordered_map<char, int> S;
        int windowStart = 0;
        
        // Use the Dynamic Sliding Window technique.
        for(int windowEnd = 0; windowEnd < s.size(); ++windowEnd)
        {
            ++S[s[windowEnd]];
            
            // Shrinking the window from the start, to get the minimum possible window.
            while(contains(S, T))
            {
                if(windowEnd - windowStart + 1 < minLen)
                {
                    minLen = windowEnd - windowStart + 1;
                    ansStart = windowStart;
                    ansEnd = windowEnd;
                }

                --S[s[windowStart]];
                ++windowStart;
            }
        }
        
        return ansStart == INT_MAX ?  ""  :  s.substr(ansStart, ansEnd - ansStart + 1);
    }
    
    bool contains(unordered_map<char, int> &S, unordered_map<char, int> &T)
    {
        for(auto &pair: T)
        {
            if(S[pair.first] < pair.second)
                return false;
        }
        
        return true;
    }
};