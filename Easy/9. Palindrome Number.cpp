class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0)
            return false;
        if(x == 0)
            return true;
        
        int input = x;
        int reverse = 0;
        while(x > 0)
        {
            reverse = (reverse * 10) + (x % 10);
            x = x / 10;
            
            if(x > 0)
            {
                if(reverse > (2147483647 - (x % 10))/10)    // x is only positive if, control reached this point.
                    return false;
            }
        }
        cout << reverse << ' ' << input << endl;
        if(reverse == input)
            return true;
        else 
            return false;
    }
};