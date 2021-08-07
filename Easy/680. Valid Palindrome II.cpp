class Solution {
public:
    bool isDeleted = false;

    bool validPalindrome(string &s, int low = 0, int high = INT_MAX)
    {
        if(s == "") return true;

        if(high == INT_MAX) 
            high = s.size() - 1;
        
        while(low < high)
        {
            if(s[low] == s[high])
            {
                ++low;
                --high;
            }

            // Delete atmost one character. Can delete either starting or ending character. 
            else if(!isDeleted)
            {
                isDeleted = true;

                if(validPalindrome(s, low, high - 1) || 
                   validPalindrome(s, low + 1, high))
                    return true;
                else
                    return false;
            }
            
            // If a character has been deleated already and still a mismatch occured.
            else
                return false;
        }
        
        return true;
    }
};