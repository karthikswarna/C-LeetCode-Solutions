class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s1)
    {
        vector<string> s2 = s1;
        for_each(s2.begin(), s2.end(), [](string &s){sort(s.begin(), s.end());});

        // idx array has the original indices of strings before the entire is sorted.
        vector<size_t> idx(s1.size());
        iota(idx.begin(), idx.end(), 0);
        stable_sort(idx.begin(), idx.end(), [&s2](size_t i1, size_t i2) {return s2[i1] < s2[i2];});
        sort(s2.begin(), s2.end());
        
        vector<vector<string>> result;
        vector<string> temp;
        for(int i = 0; i < s2.size(); ++i)
        {
            if(i == 0 || s2[i] == s2[i - 1])
                temp.push_back(s1[idx[i]]);
            else
            {
                result.push_back(temp);
                temp.clear();
                temp.push_back(s1[idx[i]]);
            }
        }
        if(temp.size() > 0)
            result.push_back(temp);

        return result;
    }
};