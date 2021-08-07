class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> S;
        for(auto i : nums)
        {
            if(S.find(i) == S.end())
                S.insert(i);
            else
                return true;
        }
        
        return false;
    }
};