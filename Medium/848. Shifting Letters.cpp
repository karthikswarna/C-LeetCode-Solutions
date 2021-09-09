class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts)
    {
        // int len = s.size();
        // First approach. Time O(N^2) Space O(N)
        // vector<int> cumShifts(len, 0);
        // for(int i = 0; i < len; ++i)
        //     for(int j = 0; j < i + 1; ++j)
        //         cumShifts[j] += shifts[i];
        
        // for(int i = 0; i < len; ++i)
        // {
        //     int total = s[i] + cumShifts[i] % 26;
        //     if(total > 122) total = total - 122 + 96;
        //     s[i] = total;
        // }
        
        // Second Approach Time: O(N), Space O(1)
        int len = s.size();
        int cumShifts = 0;
        for(int i = len - 1; i >= 0; --i)
        {
            cumShifts += shifts[i];
            cumShifts %= 26;        // We use Circular Shifting. So, we can remove redundant shifts.

            int total = s[i] + cumShifts;
            if(total > 122) total = total - 122 + 96;   // Handle the circular case when sum crosses 122 (z);

            s[i] = total;
        }

        return s;
    }
};