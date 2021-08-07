class Solution {
public:
    string removeDuplicates(string s)
    {
        string n;
        int i = 0;
        n.push_back(s[0]);
        while(i < s.size() - 1)
        {
            ++i;
            if(n.size() && n.back() == s[i])
                n.pop_back();
            else
                n.push_back(s[i]);
        }
        
        return  n;
    }
};