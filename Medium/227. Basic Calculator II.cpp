class Solution {
public:
    int calculate(string s)
    {
        stringstream ss("+" + s);
        char op;
        int currNum;
        int prevNum;
        int result = 0;
        
        while (ss >> op >> currNum)
        {
            if (op == '+' || op == '-')
            {
                currNum = (op == '+') ? currNum : -currNum;
                result += currNum;
            }
            else
            {
                currNum = (op == '*') ? prevNum * currNum : prevNum / currNum;
                
                // simulate a stack by recovering last values
                result = result - prevNum + currNum;
            }
        
            prevNum = currNum;
        }
    
        return result;
    }
};
