class Solution {
public:
    string tictactoe(vector<vector<int>>& moves)
    {
        vector<vector<char>> board(3, vector<char>(3, 0));
        for(int i = 0; i < moves.size(); ++i)
        {
            if(i % 2 == 0)
                board[moves[i][0]][moves[i][1]] = 'X';
            else
                board[moves[i][0]][moves[i][1]] = 'O';
        }
        
        int result = check(board);
        if(result == 1) return "A";
        else if(result == -1) return "B";
        
        
        // Result == 0
        if(moves.size() == 9) return "Draw";
        
        return "Pending";
    }
    
    short check(vector<vector<char>>& board)
    {
        // Check for rows
        for(int i = 0; i < 3; ++i)
        {
            int count = 0;
            for(int j = 0; j < 3; ++j)
            {
                if(board[i][j] == 'X') ++count;
                else if(board[i][j] == 'O') --count;
            }

            if(count == 3) return 1;
            if(count == -3) return -1;
        }

        // Check for columns
        for(int j = 0; j < 3; ++j)
        {
            int count = 0;
            for(int i = 0; i < 3; ++i)
            {
                if(board[i][j] == 'X') ++count;
                else if(board[i][j] == 'O') --count;
            }

            if(count == 3) return 1;
            if(count == -3) return -1;
        }
        
        // Check for diagonals
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            if(board[1][1] == 'X') return 1;
            if(board[1][1] == 'O') return -1;
        }    
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            if(board[1][1] == 'X') return 1;
            if(board[1][1] == 'O') return -1;
        }

        return 0;
    }
};