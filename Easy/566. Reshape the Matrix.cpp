class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
    {
        int m = mat.size();
        int n = mat[0].size();
        
        if(r*c != m*n)
            return mat;
        
        vector<vector<int>> reshaped(r, vector<int>(c));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                reshaped[(i * n + j) / c][(i * n + j) % c] = mat[i][j];
        
        return reshaped;
    }
};