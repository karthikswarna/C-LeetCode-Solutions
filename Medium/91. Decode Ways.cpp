class Solution {
public:
    int numDecodings(string &s, int cur = 0)
    {
        vector<int> memo(s.size(), -1);
        return numDecodingsUtil(s, 0, memo);
    }
    
    int numDecodingsUtil(string &s, int cur, vector<int> &memo)
    {
        if(cur == s.size()) return 1;
        if(cur > s.size() - 1 || s[cur] == '0') return 0;
        if(memo[cur] != -1) return memo[cur];

        int count = 0;
        
        // Decode current character
        count += numDecodingsUtil(s, cur + 1, memo);
        
        // Decode current and next characters combined.
        if(cur < s.size() - 1 && s.substr(cur, 2) >= "10" && s.substr(cur, 2) <= "26")
            count += numDecodingsUtil(s, cur + 2, memo);
    
        return memo[cur] = count;
    }
};