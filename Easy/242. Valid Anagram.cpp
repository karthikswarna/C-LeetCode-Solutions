class Solution {
public:
    // This Solution can be used with Unicode strings as well.
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> M;
        for(auto &i : s)
        {
            if(M.find(i) == M.end())
                M[i] = 1;
            else
                ++M[i];
        }
        
        for(auto &i: t)
        {
            --M[i];
            if(M[i] < 0) return false;
        }
        
        for(auto &p: M)
            if(p.second > 0) return false;
        
        return true;
    }
};