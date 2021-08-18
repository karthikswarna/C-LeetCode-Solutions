class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == word[0])
                {
                    board[i][j] = '\0';
                    
                    if(recur(board, i, j, word, 1))
                        return true;
                    
                    board[i][j] = word[0];
                }
            }
        }
        
        return false;
    }
    
    bool recur(vector<vector<char>>& board, int i, int j, string word, int cur)
    {
        if(cur == word.size()) return true;
        
        char ch = word[cur];

        // Move Down.
        if(i + 1 < board.size() &&  board[i + 1][j] == ch)
        {
            board[i + 1][j] = '\0';

            if(recur(board, i + 1, j, word, cur + 1)) return true;

            board[i + 1][j] = ch;
        }
        
        // Move Right.
        if(j + 1 < board[0].size() && board[i][j + 1] == ch)
        {
            board[i][j + 1] = '\0';
            
            if(recur(board, i, j + 1, word, cur + 1)) return true;
 
           board[i][j + 1] = ch;
        }
        
        // Move Up.
        if(i - 1 >= 0 && board[i - 1][j] == ch)
        {
            board[i - 1][j] = '\0';
            
            if(recur(board, i - 1, j, word, cur + 1)) return true;

            board[i - 1][j] = ch;
        }

        // Move Left.
        if(j - 1 >= 0 && board[i][j - 1] == ch)
        {
            board[i][j - 1] = '\0';
            
            if(recur(board, i, j - 1, word, cur + 1)) return true;
            
            board[i][j - 1] = ch;
        }

        return false;
    }
};