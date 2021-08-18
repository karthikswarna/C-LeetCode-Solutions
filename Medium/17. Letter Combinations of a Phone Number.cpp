class Solution {
public:
    const vector<string> pad =
    {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string &s, int cur = 0)
    {
        vector<string> result;
        if(cur + 1 > s.size()) return result;

        if(cur == s.size() - 1)
        {
            for(auto i: pad[(int)s[cur] - 48])
                result.push_back(string(1, i));
        }
        else
        {
            vector<string> strs = letterCombinations(s, cur + 1);
            
            for(auto ch: pad[(int)s[cur] - 48])
                for(auto str: strs)
                    result.push_back(ch + str);
        }
        
        return result;
    }
};