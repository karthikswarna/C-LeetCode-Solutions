class Solution {
public:
    int numberOfSubstrings(string s)
    {
        int len = s.size();
        int windowStart = 0;
        int count[3] = {0};
        int ans = 0;

        for(int windowEnd = 0; windowEnd < len; windowEnd++)
        {
            ++count[int(s[windowEnd]) - 97];
        
            while((count[0] > 0) && (count[1] > 0) && (count[2] > 0))
            {
                ans += len - windowEnd;

                --count[int(s[windowStart]) - 97];
                ++windowStart;
            }
        }
        
        return ans;
    }
};