class Solution {
public:
    int countBinarySubstrings(string &s, int startIdx = 0)
    {
        int count[2] = {0, 0};
        int breakPoint = INT_MIN;
        int substringCount = 0;

        if(s[startIdx] == '0') count[0]++;
        else count[1]++;

        for(int i = startIdx + 1; i < s.size(); i++)
        {
            if(s[i] == s[i - 1])
                count[int(s[i]) - 48]++;

            // Mismatch - found a break point.
            else
            {
                if(breakPoint != INT_MIN)
                {
                    substringCount += countBinarySubstrings(s, breakPoint);
                    break;
                }
                else
                {
                    breakPoint = i;
                    count[int(s[i]) - 48]++;
                }
            }
        }
        
        substringCount += min(count[0], count[1]);

        return substringCount;
    }
};