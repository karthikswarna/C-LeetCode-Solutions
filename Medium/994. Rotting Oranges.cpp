class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int minutes = -1;
        int freshCount = 0;
        
        queue<int> Q;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 2) 
                    Q.push(i * n + j);

                else if(grid[i][j] == 1)
                    ++freshCount;
            }
        }
 
        if(Q.empty() && freshCount > 0) return -1;
        
        // Special element to track the number of minutes (Similar to duplicate node to track levels in level-order traversal.)
        Q.push(-1);

        // BFS
        while(!Q.empty())
        {
            int i = Q.front() / n;
            int j = Q.front() % n;
            Q.pop();

            // If special element if found, one minute has passed (level in level-order traversal.)
            if(i < 0 || j < 0)
            {
                ++minutes;

                // If there are no more rotten oranges left, exit.
                if(Q.empty()) break;

                Q.push(-1);
                continue;
            }

            // Visit fresh neighbours, rot them, add to queue.
            if(i + 1 < m && grid[i + 1][j] == 1)
            {
                grid[i + 1][j] = 2;
                Q.push((i + 1) * n + j);
                --freshCount;
            }
            if(i - 1 >= 0 && grid[i - 1][j] == 1)
            {
                grid[i - 1][j] = 2;
                Q.push((i - 1) * n + j);
                --freshCount;
            }
            if(j + 1 < n && grid[i][j + 1] == 1)
            {
                grid[i][j + 1] = 2;
                Q.push(i * n + j + 1);
                --freshCount;
            }
            if(j - 1 >= 0 && grid[i][j - 1] == 1)
            {
                grid[i][j - 1] = 2;
                Q.push(i * n + j - 1);
                --freshCount;
            }
        }
        
        // If any oranges are still fresh, return -1;
        if(freshCount != 0) return -1;

        return minutes;
    }

    // Basic Approach using Three Loops (Simple and not bad in terms of time complexity).
//     int orangesRotting(vector<vector<int>>& grid)
//     {
//         int m = grid.size();
//         int n = grid[0].size();
        
//         int rottenCount = 0;
//         int minutes = 0;
//         while(true)
//         {
//             rottenCount = 0;

//             for(int i = 0; i < m; ++i)
//             {
//                 for(int j = 0; j < n; ++j)
//                 {
//                     if(grid[i][j] == 1)
//                     {
//                         if((i - 1 >= 0 && grid[i - 1][j] == 2) ||
//                            (i + 1 < m && grid[i + 1][j] == 2)  || 
//                            (j - 1 >= 0 && grid[i][j - 1] == 2) ||
//                            (j + 1 < n && grid[i][j + 1] == 2))
//                         {
//                             grid[i][j] |= 2;    // Use 2nd LSB to store next state. (grid[i][j] = 3)
//                             ++rottenCount;
//                         }
//                     }
//                 }
//             }

//             if(rottenCount == 0) break;

//             for(int i = 0; i < m; ++i)
//                 for(int j = 0; j < n; ++j)
//                     if(grid[i][j] == 3) 
//                         grid[i][j] = 2;

//             ++minutes;
//         }

//         for(int i = 0; i < m; ++i)
//             for(int j = 0; j < n; ++j)
//                 if(grid[i][j] == 1) return -1;

//         return minutes;
//     }
};