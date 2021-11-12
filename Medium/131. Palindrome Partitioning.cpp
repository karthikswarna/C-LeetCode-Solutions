class Solution
{
    vector<vector<string>> result;
public:
    vector<vector<string>> partition(string s, int start = 0)
    {
        vector<string> currPartition;
        generatePartitions(s, 0, currPartition);
        return result;
    }
    
    void generatePartitions(const string& s, int start, vector<string>& currPartition)
    {
        if(start >= s.size()) 
        {
            result.push_back(currPartition);
            return;
        }

        for(int i = start; i < s.size(); ++i)
        {
            if(isPalindrome(s, start, i))
            {
                currPartition.push_back(s.substr(start, i - start + 1));
                
                generatePartitions(s, i + 1, currPartition);
                
                currPartition.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end]) return false;
            
            ++start;
            --end;
        }
        
        return true;
    }
};