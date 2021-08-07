class Solution {
public:
    int firstUniqChar(string s)
    {
        array<int, 26> A = {0};
        for(int i = 0; i < s.size(); i++)
            ++A[s[i] - 'a'];

        for(int i = 0; i < s.size(); i++)
            if(A[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};