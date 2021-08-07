class Solution {
public:
    bool isMatch(string s, string p)
    {
        if(p.empty()) return s.empty();
        
        bool first_match = (!s.empty()) && (s.at(0) == p.at(0) || p.at(0) == '.');
        
        if(p.size() >= 2 && p.at(1) == '*')
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        else
            return first_match && isMatch(s.substr(1), p.substr(1));
    }
};