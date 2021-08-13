class Solution {
public:
    // This is constant space solution. More space can be used to get a faster solution.
    // Can remember the row and column numbers in two sets, and in second itertion, set those elements to 0.
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // For the cell (0,0), it can be a flag for the 0th column as well as the 0th row.
        // To differentiate this, we can set this variable to true if there is a zero in 0th column.
        // Then we can use the (0,0) cell to indicate if there is a zero in the 0th row.
        bool isCol = false;
        
        // If M[i][j] == 0, we can set the first element in `i`th row and `j`th column to 0. Which will not create discrepancies as we have already traversed those cells.
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    if(j == 0) 
                    {
                        isCol = true;
                        continue;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Traverse all rows, and if any row's first element is 0, set all elements in that row to 0.
        for(int i = 1; i < m; ++i)
            if(matrix[i][0] == 0)
                for(int j = 1; j < n; ++j)
                    matrix[i][j] = 0;

        // Traverse all columns, and if any column's first element is 0, set all elements in that columns to 0.
        for(int j = 1; j < n; ++j)
            if(matrix[0][j] == 0)
                for(int i = 1; i < m; ++i)
                    matrix[i][j] = 0;
        
        
        // Handle the special case of matrix[0][0]
        if(matrix[0][0] == 0)
            for(int j = 0; j < n; ++j)
                matrix[0][j] = 0;

        if(isCol)
            for(int i = 0; i < m; ++i)
                matrix[i][0] = 0;
    }
};