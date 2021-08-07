class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if(needle == "")
            return 0;

        int j = 0;
        int next_check = -1;
        for(int i = 0; i < haystack.size(); i++)
        {
            if(needle[j] == haystack[i])
            {
                if(next_check == -1 && haystack[i] == needle[0])
                    next_check = i;

                j++;
                if(j == needle.size())
                    return i - j + 1;
            }
            else
                if(j > 0)
                {
                    j = 0;
                    i = next_check;
                    next_check = -1;
                }
        }
        
        return -1;
    }
};