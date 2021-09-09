class Solution {
public:
    // Since the board has ints but only the 1-bit is used, we use the 2nd-bit to store the new state. 
    // At the end, replace the old state with the new state by shifting all values one bit to the right.
    void gameOfLife(vector<vector<int>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                // Find the number of live neighbours.
                // If the LSB is 1, then the cell is live
                int liveCount = -board[i][j];
                for(int a = max(i - 1, 0); a < min(i + 2, m); ++a)
                    for(int b = max(j - 1, 0); b < min(j + 2, n); ++b)
                        liveCount += board[a][b] & 1;
                
                if(liveCount == 3 || (board[i][j] == 1 && liveCount == 2))
                    board[i][j] |= 2;   // The next state will be live.
            }
        }
        
        // Shift right once to bring the 2nd bit to the first position. Note: 2nd bit represents the next gen.
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                board[i][j] >>= 1;
    }
};