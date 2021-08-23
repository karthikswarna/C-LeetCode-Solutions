class Solution
{
    vector<vector<int>> rows = vector<vector<int>>(9, vector<int>(10, 0));
    vector<vector<int>> cols = vector<vector<int>>(9, vector<int>(10, 0));
    vector<vector<vector<int>>> boxes = vector<vector<vector<int>>>(3, vector<vector<int>>(3, vector<int>(10, 0)));

public:
    void solveSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    int val = board[i][j] - '0';
                    rows[i][val] = true; cols[j][val] = true; boxes[i/3][j/3][val] = true;
                }
            }
        }

        solver(board, 0, 0);
    }
    
    bool solver(vector<vector<char>>& board, int i, int j)
    {
        if(i == 9) return true;                                 // All cells are filled.
        if(j == 9) return solver(board, i + 1, 0);              // Move to the next cell (in next row.)
        if(board[i][j] != '.') return solver(board, i, j + 1);  // Cell is not empty. Goto next cell.

        for(int val = 1; val <= 9; ++val)
        {
            if(isValid(board, i, j, val))
            {
                rows[i][val] = true; cols[j][val] = true; boxes[i/3][j/3][val] = true;
                board[i][j] = (char)(val + 48);
            
                if(solver(board, i, j + 1)) return true;
            
                board[i][j] = '.';
                rows[i][val] = false; cols[j][val] = false; boxes[i/3][j/3][val] = false;
            }
        }

        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int i, int j, int val)
    {
        if(rows[i][val] == true) return false;
        if(cols[j][val] == true) return false;
        if(boxes[i / 3][j / 3][val] == true) return false;
        return true;
    }
};