class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.size() == 1) return strs[0];
        if(strs[0].size() == 0) return ""; // just a stretch

        int maxLen = INT_MIN;
        for(int j = 1; j < strs.size(); ++j)
            maxLen = std::max(maxLen, (int)strs[j].size());

        int i = 0;
        while(i < maxLen)
        {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); ++j)
            {
                if(i >= strs[j].size() || strs[j][i] != c)
                    return strs[j].substr(0, i);
            }

            ++i;
        }
        
        return strs[0].substr(0, i);
    }
};