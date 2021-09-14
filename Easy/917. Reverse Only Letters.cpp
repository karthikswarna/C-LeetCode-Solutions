class Solution {
public:
    string reverseOnlyLetters(string s)
    {
        int low = 0;
        int high = s.size() - 1;
    
        while(low < high)
        {
            while(!isalpha(s[low]) && low < high) ++low;
            while(!isalpha(s[high]) && low < high) --high;
            swap(s[low], s[high]);
            ++low;
            --high;
        }
        
        return s;
    }
};