class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& B)
    {
        array<bool, 10> A = {false};

        for(int row = 0; row < 9; ++row)
        {
            A.fill(false);
            for(int col = 0; col < 9; ++col)
            {
                int num = B[row][col] - '0';
                if(num != -2)
                {
                    if(A[num] == false)
                        A[num] = true;
                    else
                        return false;
                }
            }
        }
        
        for(int col = 0; col < 9; ++col)
        {
            A.fill(false);
            for(int row = 0; row < 9; ++row)
            {
                int num = B[row][col] - '0';
                if(num != -2)
                {
                    if(A[num] == false)
                        A[num] = true;
                    else
                        return false;
                }
            }
        }
        
        for(int box = 0; box < 9; ++box)
        {
            A.fill(false);
            for(int row = 0; row < 3; ++row)
            {
                for(int col = 0; col < 3; ++col)
                {
                    int num = B[row + 3 * (box / 3)][col + 3 * (box % 3)] - '0';
                    if(num != -2)
                    {
                        if(A[num] == false)
                            A[num] = true;
                        else
                            return false;
                    }
                }
            }
        }

        return true;
    }
};