class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& A)
    {
        int m = A.size();
        int n = A[0].size();

        // 10^5 because the distance cannot be greater than 10^4 (as the problem says [1 <= m, n <= 10^4])
        // If we use INT_MAX, adding 1 causes overflow.
        vector<vector<int>> table(m, vector<int>(n, 100000)); 
        
        // Minimum distance from top and left neighbours.
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(A[i][j] == 0)
                    table[i][j] = 0;
                
                else if(i - 1 >= 0 && j - 1 >= 0)
                    table[i][j] = std::min(table[i - 1][j], table[i][j - 1]) + 1;

                else if(i - 1 >= 0)
                    table[i][j] = table[i - 1][j] + 1;

                else if(j - 1 >= 0)
                    table[i][j] = table[i][j - 1] + 1;
            }
        }

        // Minimum distance from bottom and right neighbours. Take the minimum of above pass and current pass.
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(A[i][j] == 0)
                    table[i][j] = 0;
                
                else if(i + 1 < m && j + 1 < n)
                    table[i][j] = std::min( {table[i][j], table[i + 1][j] + 1, table[i][j + 1] + 1} );

                else if(i + 1 < m)
                    table[i][j] = std::min(table[i][j], table[i + 1][j] + 1);

                else if(j + 1 < n)
                    table[i][j] = std::min(table[i][j], table[i][j + 1] + 1);
            }
        }

        return table;
    }
};