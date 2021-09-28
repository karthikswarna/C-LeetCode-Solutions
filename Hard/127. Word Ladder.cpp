class Solution {
public:
    // Without creating ADJACENT LIST - TLE
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList)
//     {
//         unordered_map<string, int> distance;
//         queue<string> Q;
//         string front;
//         int dist;
        
//         distance[beginWord] = 1;
//         Q.push(beginWord);
        
//         while(!Q.empty())
//         {
//             // auto [front, dist] = Q.front();  // C++ 17
//             front = Q.front();
//             Q.pop();

//             if(front == endWord) return distance[front];

//             // Visit all its neighbours (which are not visited previously).
//             for(auto word: wordList)
//             {
//                 if(distance[word] == 0 && validNextWord(front, word))
//                 {
//                     distance[word] = distance[front] + 1;
//                     Q.push(word);
//                 }
//             }
//         }
        
//         return 0;
//     }
    
    // Returns true if start and end differs only by one character.
//     bool validNextWord(string& start, string& end)
//     {
//         bool found = false;
//         for(int i = 0; i < start.size(); ++i)
//         {
//             if(start[i] != end[i])
//             {
//                 if(!found) found = true;
//                 else return false;
//             }
//         }
        
//         return true;
//     }
    
    // BFS with ADJACENT LIST.
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        // Create an ADJACENT LIST.
        unordered_map<string, vector<string>> adjList;
        for(auto str: wordList)
        {
            for(int i = 0; i < beginWord.size(); ++i)
            {
                string newStr = str;
                newStr[i] = '*';

                adjList[newStr].push_back(str);
            }
        }
        
        // BFS
        unordered_map<string, int> distance;
        queue<string> Q;
        string front;
        int dist;
        
        distance[beginWord] = 1;
        Q.push(beginWord);
        
        while(!Q.empty())
        {
            // auto [front, dist] = Q.front();  // C++ 17
            front = Q.front();
            Q.pop();

            if(front == endWord) return distance[front];

            // Visit all its neighbours (which are not visited previously).
            for(int i = 0; i < beginWord.size(); ++i)
            {
                string newStr = front;
                newStr[i] = '*';
                for(auto neighbour: adjList[newStr])
                {
                    if(distance[neighbour] == 0)
                    {
                        distance[neighbour] = distance[front] + 1;
                        Q.push(neighbour);
                    }
                }
            }
        }
        
        return 0;
    }
};