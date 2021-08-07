class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int lastSpacePos = -1;
        int charsSinceLastSpace = 0;
        int prevLength = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                lastSpacePos = i;
                prevLength = charsSinceLastSpace == 0 ? prevLength : charsSinceLastSpace;
                charsSinceLastSpace = 0;
            }
            
            if(s[i] != ' ')
                charsSinceLastSpace++;   
        }
        
        return charsSinceLastSpace == 0 ? prevLength : charsSinceLastSpace;
    }
};