class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        // Start searching from the top right corner. Remove one row / one col at a time.
        int row = 0;
        int col = matrix[0].size() - 1;
        while(col >= 0 && row <= matrix.size() - 1)
        {
            if(matrix[row][col] == target) return true;

            else if(matrix[row][col] > target) col--;

            else if(matrix[row][col] < target) row++;
        }

        return false;
    }
};