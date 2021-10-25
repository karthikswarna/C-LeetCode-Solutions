class Solution {
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> M;
        char mostFreqChar;
        int maxFreq = 0;
        for(auto ch : s)
        {
            ++M[ch];
            if(M[ch] > maxFreq)
            {
                maxFreq = M[ch];
                mostFreqChar = ch;
            }
        }

        if(maxFreq > ceil((float)s.size()/2)) return "";
        
        // Fill the string with most frequent character in even positions.
        int id = 0;
        while(M[mostFreqChar] > 0)
        {
            s[id] = mostFreqChar;
            id += 2;
            --M[mostFreqChar];
        }
        
        // Fill all the other characters in remaining positions 
        // (First complete even positions, then odd ones.) 
        for(auto charFreq: M)
        {
            while(M[charFreq.first] > 0)
            {
                if(id >= s.size()) id = 1;
                
                s[id] = charFreq.first;
                id += 2;
                --M[charFreq.first];
            }
        }
        
        return s;
    }
};