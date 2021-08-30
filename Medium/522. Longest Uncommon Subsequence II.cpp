class Solution {
public:
    int findLUSlength(vector<string>& strs)
    {
        unordered_map<string, unsigned int> M;
        for(auto &str: strs)
            ++M[str];
        
        sort(strs.begin(), strs.end(), [](string a, string b){ return a.size() > b.size(); });

        for(int i = 0; i < strs.size(); ++i)
        {
            // If a string has multiple copies it cannot be an LUS.
            if(M[strs[i]] > 1) continue;
            
            // Check if any previous strings has current string as substring.
            int j = 0;
            for(; j < i; ++j)
                if(isSubsequence(strs[i], strs[j])) 
                    break;

            if(j == i) return strs[i].size();
        }
        
        return -1;
    }
    
    // True if a is a subsequence of b.
    bool isSubsequence(string a, string b)
    {
        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size())
        {
            if(a[i] == b[j]) 
                ++i;
        
            ++j;
        }
        
        cout <<  (i == a.size()) << endl;
        return i == a.size();
    }
};