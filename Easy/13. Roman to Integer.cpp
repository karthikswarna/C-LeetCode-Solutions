class Solution {
public:
    int getValue(char c)
    {
        switch(c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }

        return -1;
    }
    
    int romanToInt(string s)
    {
        // unordered_map<char, int> R = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                                      // {'C', 100}, {'D', 500}, {'M', 1000}};
    
        int len = s.size();
        int result = 0;
        int val;

        for(int i = 0; i < len; ++i)
        {
            val = getValue(s[i]);

            if(i < len - 1 && val < getValue(s[i + 1]))
                result -= val;
            else
                result += val;

        }
        
        return result;
    }
};