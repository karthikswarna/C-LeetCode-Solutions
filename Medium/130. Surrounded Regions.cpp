class Solution
{
public:
    void solve(vector<vector<char>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        
        // Visit all islands that end in a boundary (dont have water on all sides). 
        for(int i = 0; i < m; ++i)
        {
            if(board[i][0] == 'O') bfs(board, i, 0);
            if(board[i][n - 1] == 'O') bfs(board, i, n - 1); 
        }

        for(int j = 0; j < n; ++j)
        {
            if(board[0][j] == 'O') bfs(board, 0, j);
            if(board[m - 1][j] == 'O') bfs(board, m - 1, j); 
        }

        // Change all remaining islands (marked by O) to X.
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(board[i][j] == 'O') board[i][j] = 'X';

        // Change all explored islands (marked by E) to O.
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(board[i][j] == 'E') board[i][j] = 'O';                
    }
    
    void bfs(vector<vector<char>>& board, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();
        
        queue<int> Q;
        Q.push(i * n + j);
        
        while(!Q.empty())
        {
            int front = Q.front();
            Q.pop();
            
            i = front / n;
            j = front % n;
            
            if(i >= 0 && i < m && j >=0 && j < n && board[i][j] == 'O')
            {
                board[i][j] = 'E';
                Q.push((i - 1) * n + j);
                Q.push((i + 1) * n + j);
                Q.push(i * n + (j - 1));
                Q.push(i * n + (j + 1));
            }
        }
    }
};