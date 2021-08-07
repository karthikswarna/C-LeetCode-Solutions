class Solution {
public:
    bool isPalindrome(string s)
    {
        int low = 0;
        int high = s.size() - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        while(low < high)
        {
            while(iswalnum(s[low]) == 0 && low < high) low++;
            while(iswalnum(s[high]) == 0 && low < high) high--;

            if(s[low] == s[high])
            {
                low++;
                high--;
            }

            else
                return false;
        }
        
        return true;
    }
};