class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int max = 0;
        for(int i = 0; i < s.length(); i++)
        {
            unordered_set<char> charSet;
            int length = 0;
            for(int j = i; j < s.length(); j++)
            {
                if(charSet.find(s[j]) != charSet.end())
                    break;
                length++;
                charSet.insert(s[j]);
            }
            if(length > max)
                max = length;
        }
        
        return max;
    }
};