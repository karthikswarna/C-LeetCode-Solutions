class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
    {
        // This groups the words having same letters into same group. 
        // (mask - num of words) mapping.
        unordered_map<int, int> wordCount;
        for (string& word : words)
            ++wordCount[bitmask(word)];

        vector<int> answer(puzzles.size());
        int i = -1;
        for(string& puzzle: puzzles)
        {
            int firstChar = 1 << (puzzle[0] - 97);
            int count = wordCount[firstChar];

            int mask = bitmask(puzzle.substr(1));

            // iterate over submasks
            for (int submask = mask; submask; submask = (submask - 1) & mask)
                count += wordCount[submask | firstChar];  // add first character

            answer[++i] = count;
        }
        
        return answer;
    }
    
    int bitmask(const string& word)
    {
        int mask = 0;
        for (char ch : word)
            mask |= (1 << (ch - 97));

        return mask;
    }

    // Initial Solution - TLE
//     vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
//     {
//         int m = words.size();
//         int n = puzzles.size();

//         // "wordCharCounts"  works like a list of Hash Tables.
//         vector<int> wordCharCounts(m, 0);
//         for(int i = 0; i < m; ++i)
//             for(auto ch: words[i])
//                 wordCharCounts[i] |= (1 << (ch - 97));

//         // "puzzleCharCounts"  works like a list of Hash Tables.
//         vector<int> puzzleCharCounts(n, 0);
//         for(int i = 0; i < n; ++i)
//             for(auto ch: puzzles[i])
//                 puzzleCharCounts[i] |= (1 << (ch - 97));

//         vector<int> answer(n);
//         for(int i = 0; i < n; ++i)
//         {
//             int count = 0;
//             for(int j = 0; j < m; ++j)
//             {
//                 // if jth word contains the first letter of ith puzzle.
//                 if( wordCharCounts[j] & (1 << (puzzles[i][0] - 97)) )

//                     // if all the letters in jth word are in ith puzzle
//                     if((wordCharCounts[j] & puzzleCharCounts[i]) == wordCharCounts[j])
//                         ++count;
//             }

//             answer[i] = count;
//         }
        
//         return answer;
//     }
};