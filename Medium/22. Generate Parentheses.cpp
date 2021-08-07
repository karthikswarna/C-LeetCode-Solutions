class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> v;
        generateParenthesis(string(), n, 0, 0, 0, v);
        return v;
    }
    
    void generateParenthesis(string s, int n, int o, int c, int l, vector<string> &v)
    {   
        if(o == n && c == n && l == 0)
        {
            v.push_back(s);
            return;
        }
        
        if(o > n || l < 0)
            return;
        
        generateParenthesis(s+'(', n, o+1, c, l+1, v);
        generateParenthesis(s+')', n, o, c+1, l-1, v);
    }
};