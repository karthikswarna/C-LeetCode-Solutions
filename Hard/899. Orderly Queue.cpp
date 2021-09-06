class Solution {
public:
    string orderlyQueue(string s, int k)
    {
        string ans = s;
        if(k == 1)
        {
            for(int i = 0; i < s.size(); ++i)
            {
                string temp = s.substr(i, s.size() - i) + s.substr(0, i);
                if(temp < ans) ans = temp;
            }
        }
        else        // If k > 1, we can perform the operation any number of times and hence can finally sort it.
        {
            sort(s.begin(), s.end());
            return s;
        }
        
        return ans;
    }
};