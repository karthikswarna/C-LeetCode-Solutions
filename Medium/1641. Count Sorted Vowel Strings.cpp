class Solution
{
public:
    int countVowelStrings(int n)
    {
        return countVowelStrings(n, 0);
    }

    int countVowelStrings(int n, int last_index)
    {
        if(n == 0) return 1;

        int result = 0;
        for(int i = last_index; i < 5; i++)
            result += countVowelStrings(n - 1, i);
    
        return result;
    }

};