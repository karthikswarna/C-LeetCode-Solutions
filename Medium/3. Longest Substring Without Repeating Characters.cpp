class Solution {
public:
    // O(N) Sliding Window Solution.
    int lengthOfLongestSubstring(string s) 
    {
        int len = s.size();
        int maxLen = 0;
        
        unordered_map<char, int> M;

        int windowStart = 0;
        for(int windowEnd = 0; windowEnd < len; ++windowEnd)
        {
            ++M[s[windowEnd]];

            // Window Shrinking.
            while(M[s[windowEnd]] > 1)
            {
                --M[s[windowStart]];
                ++windowStart;
            }

            maxLen = std::max(windowEnd - windowStart + 1, maxLen);
        }
        
        return maxLen;
    }

    // O(N^2) solution
    // int lengthOfLongestSubstring(string s) 
    // {
    //     int max = 0;
    //     for(int i = 0; i < s.length(); i++)
    //     {
    //         unordered_set<char> charSet;
    //         int length = 0;
    //         for(int j = i; j < s.length(); j++)
    //         {
    //             if(charSet.find(s[j]) != charSet.end())
    //                 break;
    //             length++;
    //             charSet.insert(s[j]);
    //         }
    //         if(length > max)
    //             max = length;
    //     }
        
    //     return max;
    // }
};