class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> S;
        
        for(int i = 0; i < tokens.size(); ++i)
        {
            string op = tokens[i];
            if(op == "+" || op == "-" || op == "*" || op == "/")
            {
                int a = S.top(); S.pop();
                int b = S.top(); S.pop();

                if(op == "+") S.push(a + b);
                else if(op == "-") S.push(b - a);
                else if(op == "*") S.push(a * b);
                else S.push(b / a);
            }
            else
               S.push(stoi(tokens[i]));
        }
        
        return S.top();
    }
};