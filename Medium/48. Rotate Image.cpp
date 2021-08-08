class Solution {
public:
    // My original Solution.
    void rotate(vector<vector<int>>& matrix)
    {
        int N = matrix.size();
        for(int i = 0; i < N / 2; ++i) // row
        {
            int n = N - i - 1; // Size for the current square-shaped ring that is being rotated. 
            for(int j = i; j < n; ++j) // column
            {
                swap(matrix[i][j], matrix[j][n]);
                swap(matrix[i][j], matrix[n][n - j + i]);
                swap(matrix[i][j], matrix[n - j + i][i]);
            }
        }
    }

    // A faster approach. Transpose + Row Reversal
    // void rotate(vector<vector<int>>& matrix)
    // {
    //     int N = matrix.size();

    //     // Taking the transpose of the original matrix.
    //      for (int i = 0; i < N; ++i)
    //         for (int j = 0; j < i; ++j)
    //             swap(matrix[i][j], matrix[j][i]);

    //     // Reversing the rows of transposed matrix. The resultant gives rotated 90 degrees in clockwise.
    //     for (int i = 0; i < N; ++i)
    //         reverse(matrix[i].begin(), matrix[i].end());
    // }
};